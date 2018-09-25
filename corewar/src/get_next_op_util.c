/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_op_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 09:01:30 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/25 18:30:54 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

typedef struct s_process	t_process;

static int	set_ind(t_process *bot, int *poffset, int i, t_op op)
{
	int		offset;
	int		ind_offset;
	char	big_e[4];
	int		pc;

	pc = bot->next_pc;
	offset = *poffset;
	big_e[0] = 0;
	big_e[1] = 0;
	big_e[2] = g_env.memory[WRAP_MEM(offset++)];
	big_e[3] = g_env.memory[WRAP_MEM(offset++)];
	ind_offset = (short)f_big_to_little_endian(big_e);
	if (op.bytecode == 3 || op.bytecode == 13)
		bot->args[i] = ind_offset;
	else
	{
		ind_offset = (op.bytecode < 13) ? ind_offset % IDX_MOD : ind_offset;
		big_e[0] = g_env.memory[WRAP_MEM(pc + ind_offset++)];
		big_e[1] = g_env.memory[WRAP_MEM(pc + ind_offset++)];
		big_e[2] = g_env.memory[WRAP_MEM(pc + ind_offset++)];
		big_e[3] = g_env.memory[WRAP_MEM(pc + ind_offset)];
		bot->args[i] = f_big_to_little_endian(big_e);
	}
	*poffset = offset;
	bot->is_reg[i] = false;
	return (0);
}

static int	set_dir(t_process *bot, int *poffset, int i, t_op op)
{
	int		offset;
	char	big_e[4];

	offset = *poffset;
	if (!op.direct_index)
	{
		big_e[0] = g_env.memory[WRAP_MEM(offset++)];
		big_e[1] = g_env.memory[WRAP_MEM(offset++)];
	}
	big_e[2] = g_env.memory[WRAP_MEM(offset++)];
	big_e[3] = g_env.memory[WRAP_MEM(offset++)];
	if (op.direct_index)
		bot->args[i] = (short)f_big_to_little_endian(big_e);
	else
		bot->args[i] = f_big_to_little_endian(big_e);
	*poffset = offset;
	bot->is_reg[i] = false;
	return (0);
}

static int	set_reg(t_process *bot, int *poffset, int i)
{
	int offset;

	offset = *poffset;
	bot->args[i] = g_env.memory[WRAP_MEM(offset++)] - 1;
	if (bot->args[i] < 0 || bot->args[i] > REG_NUMBER - 1)
		return (-1);
	bot->is_reg[i] = true;
	*poffset = offset;
	return (0);
}

int			set_arg_value(t_process *bot, int arg_types[MAX_ARGS_NUMBER])
{
	int		offset;
	t_op	op;
	int		i;

	op = g_op_tab[(int)g_env.memory[bot->next_pc] - 1];
	offset = WRAP_MEM(bot->next_pc + 1 + op.has_encoding);
	i = -1;
	while (++i < op.argc)
		if (arg_types[i] == T_REG)
		{
			if (set_reg(bot, &offset, i))
				return (-1);
		}
		else if (arg_types[i] == T_DIR)
			set_dir(bot, &offset, i, op);
		else if (arg_types[i] == T_IND)
			set_ind(bot, &offset, i, op);
		else
			return (-1);
	return (0);
}
