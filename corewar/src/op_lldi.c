/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:25:23 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/12 13:55:22 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_lldi(struct s_process *bot)
{
	int		*args;
	int		offset;
	char	*mem;
	char	big_e[4];

	print_op_basics(bot, "ldi");
	args = bot->args;
	args[0] = (bot->is_reg[0]) ? bot->reg[args[0]] : args[0];
	args[1] = (bot->is_reg[1]) ? bot->reg[args[1]] : args[1];
	offset = bot->current_pc + args[0] + args[1];
	mem = g_env.memory;
	big_e[0] = mem[WRAP_MEM(offset)];
	big_e[1] = mem[WRAP_MEM(offset + 1)];
	big_e[2] = mem[WRAP_MEM(offset + 2)];
	big_e[3] = mem[WRAP_MEM(offset + 3)];
	bot->reg[args[2]] = f_big_to_little_endian(big_e);
	bot->carry = !(bot->reg[args[2]]);
}
