/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:15:10 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/17 12:50:02 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_ldi(struct s_process *bot)
{
	int		offset;
	char	big_e[4];

	// print_op_basics(bot, "ldi");
	bot->args[0] = (bot->is_reg[0]) ? bot->reg[bot->args[0]] : bot->args[0];
	bot->args[1] = (bot->is_reg[1]) ? bot->reg[bot->args[1]] : bot->args[1];
	offset = bot->current_pc + WRAP_IDX(bot->args[0] + bot->args[1]);
	big_e[0] = g_env.memory[WRAP_MEM(offset)];
	big_e[1] = g_env.memory[WRAP_MEM(offset + 1)];
	big_e[2] = g_env.memory[WRAP_MEM(offset + 2)];
	big_e[3] = g_env.memory[WRAP_MEM(offset + 3)];
	bot->reg[bot->args[2]] = f_big_to_little_endian(big_e);
	bot->carry = !(bot->reg[bot->args[2]]);
}
