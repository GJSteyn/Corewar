/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:14:33 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/25 13:41:17 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_st(struct s_process *bot)
{
	char	big_e[4];
	int		offset;

	if (bot->is_reg[1])
		bot->reg[bot->args[1]] = bot->reg[bot->args[0]];
	else
	{
		f_little_to_big_endian(bot->reg[bot->args[0]], big_e);
		offset = bot->current_pc + WRAP_IDX(bot->args[1]);
		g_env.memory[WRAP_MEM(offset++)] = big_e[0];
		g_env.memory[WRAP_MEM(offset++)] = big_e[1];
		g_env.memory[WRAP_MEM(offset++)] = big_e[2];
		g_env.memory[WRAP_MEM(offset)] = big_e[3];
	}
}

void	op_st_vis(struct s_process *bot)
{
	char	big_e[4];
	int		offset;
	int		player;

	if (bot->is_reg[1])
	{
		bot->reg[bot->args[1]] = bot->reg[bot->args[0]];
	}
	else
	{
		player = GET_OWNER(bot->current_pc);
		f_little_to_big_endian(bot->reg[bot->args[0]], big_e);
		offset = bot->current_pc + WRAP_IDX(bot->args[1]);
		SET_VIS_MEM(WRAP_MEM(offset), big_e[0], player);
		g_env.memory[WRAP_MEM(offset++)] = big_e[0];
		SET_VIS_MEM(WRAP_MEM(offset), big_e[1], player);
		g_env.memory[WRAP_MEM(offset++)] = big_e[1];
		SET_VIS_MEM(WRAP_MEM(offset), big_e[2], player);
		g_env.memory[WRAP_MEM(offset++)] = big_e[2];
		SET_VIS_MEM(WRAP_MEM(offset), big_e[3], player);
		g_env.memory[WRAP_MEM(offset)] = big_e[3];
	}
}

void	op_st_verb(struct s_process *bot)
{
	char	big_e[4];
	int		offset;

	START_VERB(
		PRINT_PROCESS("st");
		PRINT_REG(bot->args[0] + 1);)
	if (bot->is_reg[1])
	{
		bot->reg[bot->args[1]] = bot->reg[bot->args[0]];
		START_VERB(
			PRINT_REG(bot->args[1] + 1);
			PRINT_ENDL;)
	}
	else
	{
		START_VERB(
			PRINT_ARG(bot->args[1]);
			PRINT_ENDL;)
		f_little_to_big_endian(bot->reg[bot->args[0]], big_e);
		offset = bot->current_pc + WRAP_IDX(bot->args[1]);
		g_env.memory[WRAP_MEM(offset++)] = big_e[0];
		g_env.memory[WRAP_MEM(offset++)] = big_e[1];
		g_env.memory[WRAP_MEM(offset++)] = big_e[2];
		g_env.memory[WRAP_MEM(offset)] = big_e[3];
	}
}
