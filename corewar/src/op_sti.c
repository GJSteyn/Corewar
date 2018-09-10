/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 07:50:28 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/10 09:53:59 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_sti(struct s_process *bot)
{
	char	*mem;
	int		offset;
	int		*args;
	char	big_e[4];

	mem = g_env.memory;
	args = bot->args;
	args[0] = bot->reg[args[0]];
	f_little_to_big_endian(args[0], big_e);
	args[1] = (bot->is_reg[1]) ? bot->reg[args[1]] : args[1];
	args[2] = (bot->is_reg[2]) ? bot->reg[args[2]] : args[2];
	offset = WRAP_MEM(bot->current_pc + (args[1] % IDX_MOD) + (args[2] % IDX_MOD));
	mem[offset] = big_e[0];
	mem[offset + 1] = big_e[1];
	mem[offset + 2] = big_e[2];
	mem[offset + 3] = big_e[3];
	f_printf("op: sti\n");
}
