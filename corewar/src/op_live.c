/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 06:25:52 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/24 13:36:01 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_live(struct s_process *bot)
{
	int		player_nbr;

	// print_op_basics(bot, "live");
	g_env.vis_env.player_live[-bot->created_by -1]++;
	player_nbr = -bot->args[0];
	if (player_nbr > 0 && player_nbr <= (int)g_env.player_total)
		g_env.last_live = player_nbr;
	bot->live++;
	g_env.live_counter++;
}
