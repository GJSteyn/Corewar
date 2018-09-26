/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 06:25:52 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/26 12:29:33 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_live(struct s_process *bot)
{
	int		player_nbr;

	// needs to be reviewed
	player_nbr = -bot->args[0];
	if (player_nbr > 0 && player_nbr <= (int)g_env.player_total)
	{
		g_env.vis_env.player_live[player_nbr - 1]++;
		g_env.last_live = player_nbr;
		g_env.vis_env.player_last_live[player_nbr - 1] = g_env.cycles;
	}
	bot->live++;
	g_env.live_counter++;
}


void	op_live_verb(struct s_process *bot)
{
	int		player_nbr;

	player_nbr = -bot->args[0];
	if (player_nbr > 0 && player_nbr <= (int)g_env.player_total)
	{
		(VERB_LIVES) ? f_printf("Player %d is ALIVE!\n", player_nbr) : 0;
		g_env.last_live = player_nbr;
	}
	START_VERB(
	PRINT_PROCESS("live");
	PRINT_ARG0;
	PRINT_ENDL;)
	bot->live++;
	g_env.live_counter++;
}
