/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:14:33 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/13 17:26:06 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "op_function.h"

void	op_st(struct s_process *bot)
{
	char	big_e[4];
	int		offset;

	print_op_basics(bot, "st");
	if (bot->is_reg[1])
	{
		bot->reg[bot->args[1]] = bot->reg[bot->args[0]];
		f_printf("r%d -> r%d\n", bot->args[1] + 1, bot->args[0] + 1);
	}
	else
	{
		f_printf("r%d -> %d\n", bot->args[0] + 1, bot->args[1]);
		f_little_to_big_endian(bot->reg[bot->args[0]], big_e);
		offset = bot->current_pc + WRAP_IDX(bot->args[1]);
		g_env.memory[WRAP_MEM(offset)] = big_e[0];
		g_env.memory[WRAP_MEM(offset + 1)] = big_e[1];
		g_env.memory[WRAP_MEM(offset + 2)] = big_e[2];
		g_env.memory[WRAP_MEM(offset + 3)] = big_e[3];
	}
}
