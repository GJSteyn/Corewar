/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:09:15 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/11 10:58:48 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

typedef struct s_process	t_process;

int		set_arg_types(char *mem, int types[MAX_ARGS_NUMBER])
{
	t_op	op;
	int		enc;
	int		i;

	op = g_op_tab[(int)mem[0] - 1];
	if (op.has_encoding) //might need to be adjusted with diffrent name
	{
		enc = mem[1];
		i = -1;
		while (++i < op.argc)
		{
			if (!((types[i] = DECODE(enc, i)) & op.arg_type[i]))
				return (-1);
		}
	}
	else
		types[0] = op.arg_type[0];
	return (0);
}

int		set_arg_value(t_process *bot, int arg_types[MAX_ARGS_NUMBER])
{
	int		offset;
	t_op	op;
	int		i;
	char 	big_endian[4];
	int		ind_offset;

	op = g_op_tab[(int)g_env.memory[bot->current_pc] - 1];
	offset = WRAP_MEM(bot->current_pc + 1 + op.has_encoding);
	i = -1;
	// f_printf("setting_op: %s\n", op.mnu);
	while (++i < op.argc)
	{
		f_bzero(big_endian, 4);
		if (arg_types[i] == T_REG)
		{
			bot->args[i] = g_env.memory[WRAP_MEM(offset++)];
			bot->is_reg[i] = true;
		}
		else if (arg_types[i] == T_DIR)
		{
			if (!op.direct_index)
			{
				big_endian[0] = g_env.memory[WRAP_MEM(offset++)];
				big_endian[1] = g_env.memory[WRAP_MEM(offset++)];
			}
			big_endian[2] = g_env.memory[WRAP_MEM(offset++)];
			big_endian[3] = g_env.memory[WRAP_MEM(offset++)];
			if (op.direct_index)
				bot->args[i] = (short)f_big_to_little_endian(big_endian);
			else
				bot->args[i] = f_big_to_little_endian(big_endian);
			bot->is_reg[i] = false;
		}
		else if (arg_types[i] == T_IND)
		{
			big_endian[2] = g_env.memory[WRAP_MEM(offset++)];
			big_endian[3] = g_env.memory[WRAP_MEM(offset++)];
			ind_offset = (short)f_big_to_little_endian(big_endian);
			if (op.bytecode == 3)
				bot->args[i] = ind_offset;
			else
			{
				ind_offset = (op.bytecode < 13) ? ind_offset % IDX_MOD : ind_offset;
				big_endian[0] = g_env.memory[WRAP_MEM(bot->current_pc + ind_offset++)];
				big_endian[1] = g_env.memory[WRAP_MEM(bot->current_pc + ind_offset++)];
				big_endian[2] = g_env.memory[WRAP_MEM(bot->current_pc + ind_offset++)];
				big_endian[3] = g_env.memory[WRAP_MEM(bot->current_pc + ind_offset++)];
				bot->args[i] = f_big_to_little_endian(big_endian);
				bot->is_reg[i] = false;
			}
		}
		else
			return (-1);
	}
	// f_printf("offset: %d\n", offset);
	bot->next_pc = WRAP_MEM(offset);
	return (0);
}

int		assign_args(t_process *bot)
{
	int		args[MAX_ARGS_NUMBER];

	if (set_arg_types(g_env.memory + bot->current_pc, args) < 0)
		return (-1);
	if (set_arg_value(bot, args) < 0)
		return (-1);
	return (0);
}

void 	get_next_op(t_process *bot)
{
	char 	*current;

	current = g_env.memory + bot->next_pc;
	if (*current < 1 || *current > 16 || assign_args(bot))
		bot->next_pc = (bot->next_pc++) % MEM_SIZE;
	else
	{	
		bot->delay = g_op_tab[(int)*current - 1].cost;
		bot->op = op_function(*current);
	}
}

void	run_cycle(void **process)
{
	t_process *bot;
	bot = (t_process*)*process;
	if (bot->delay > 0)
		;
	else if (!bot->delay)
	{
		bot->op(bot);
		bot->current_pc = bot->next_pc;
		get_next_op(bot);
	}
	else
		get_next_op(bot);
	bot->delay--;
}

int		main(int argc, char *argv[])
{
	t_list	*process_list;

	if (!(argc == 2))
		return (0);
	g_env.player_total = 1;
	g_env.process_list = list_create(free);
	process_list = g_env.process_list;
	list_append(process_list, load_bot(argv[1], 1));
	// print_memory();
	// f_printf("\n");
	// print_bot(list_get(process_list, 0));
	// f_printf("\n");
	int i = -1;
	while (++i < 2022)
	{
	//	f_printf("[%d]\n", i);
		list_iterate(process_list, run_cycle);
	}
	f_printf("\n");
	print_memory();
	f_printf("\n");
	print_bot(list_get(process_list, 0));
	f_printf("bot_no: %lu", process_list->size);
}
