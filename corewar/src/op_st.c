/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:14:33 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/11 15:02:36 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "op_function.h"

void	op_st(struct s_process *bot)
{
	int		*args;
	char	big_e[4];
	char	*mem;
	int		offset;

	args = bot->args;
	f_little_to_big_endian(bot->reg[args[0]], big_e);
	offset = bot->current_pc + WRAP_IDX(args[1]);
	mem = g_env.memory;
	mem[WRAP_MEM(offset)] = big_e[0];
	mem[WRAP_MEM(offset + 1)] = big_e[1];
	mem[WRAP_MEM(offset + 2)] = big_e[2];
	mem[WRAP_MEM(offset + 3)] = big_e[3];
	f_printf("op: st\n");
}
