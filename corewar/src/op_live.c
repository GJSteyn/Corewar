/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 06:25:52 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/27 10:35:47 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_live(struct s_process *bot)
{
	int		player_nbr;

	player_nbr = -bot->args[0];
	if (player_nbr > 0 && player_nbr <= (int)g_env.player_total)
	{
		g_env.vis_env.player_live[player_nbr - 1]++;
		g_env.last_live = player_nbr;
		g_env.vis_env.player_last_live[player_nbr - 1] = g_env.cycles;
		if (IS_FLAG_SET(FLAG_LIVE))
			f_printf("A process shows that player %d (%s) is alive\n",
				player_nbr,	g_env.vis_env.champs[player_nbr - 1]);
	}
	bot->live++;
	g_env.live_counter++;
}

void	op_live_vis(struct s_process *bot)
{
	int		player_nbr;

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
