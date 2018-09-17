/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:16:24 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/17 12:41:13 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

typedef struct s_process	t_process;

int		get_arg_types(t_process *bot, int types[MAX_ARGS_NUMBER])
{
	t_op	op;
	int		enc;
	int		i;
	char	*mem;
	int		ret;

	mem = g_env.memory + bot->current_pc;
	op = g_op_tab[(int)mem[0] - 1];
	ret = 0;
	if (op.has_encoding)
	{
		enc = mem[1];
		i = -1;
		while (++i < op.argc)
		{
			if (!((types[i] = DECODE(enc, i)) & op.arg_type[i]))
				ret = -1;
		}
	}
	else
		types[0] = op.arg_type[0];
	return (ret);
}

int		assign_args(t_process *bot, int op_idx)
{
	int		arg_types[MAX_ARGS_NUMBER];
	t_op	op;
	int		next;
	int		i;
	int		ret;

	op = g_op_tab[op_idx - 1];
	ret = 0;
	f_bzero(arg_types, sizeof(arg_types));
	ret = get_arg_types(bot, arg_types);
	next = 1 + op.has_encoding;
	i = -1;
	while (++i < op.argc)
	{
		next += TYPE_BYTES(arg_types[i]);
		next -= (arg_types[i] == T_DIR && op.direct_index) ? 2 : 0;
	}
	bot->next_pc = bot->current_pc + next;
	if (ret < 0 || set_arg_value(bot, arg_types) < 0)
		return (-1);
	return (0);
}

void	get_next_op(t_process *bot)
{
	int		op_idx;

	op_idx = (int)g_env.memory[(bot->next_pc % MEM_SIZE)];
	if (op_idx >= 1 && op_idx <= 16)
	{
		bot->delay = g_op_tab[op_idx - 1].cost;
		if (!(assign_args(bot, op_idx)))
			bot->op = op_function(op_idx);
		else
			bot->op = NULL;
	}
}
