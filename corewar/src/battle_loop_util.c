/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle_loop_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:03:14 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/26 13:36:42 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

typedef struct s_process	t_process;

int		kill(bool (*kill_check)(void*))
{
	t_list	*process_list;

	process_list = g_env.process_list;
	list_remove_if(process_list, kill_check);
	if (g_env.live_counter >= NBR_LIVE || g_env.last_delta == MAX_CHECKS)
	{
		g_env.delta_count++;
		g_env.last_delta = 1;
		g_env.cycle_to_die = CYCLE_TO_DIE - (g_env.delta_count * CYCLE_DELTA);
		if (VERB_CYCLES && !IS_FLAG_SET(FLAG_NCURSES))
			f_printf("Cycle to die is now %d\n", g_env.cycle_to_die);
	}
	else
	{
		g_env.last_delta++;
		if ((g_env.cycle_to_die = CYCLE_TO_DIE - (g_env.delta_count * CYCLE_DELTA)) < 0)
			return(1);
	}
	g_env.live_counter = 0;
	return (0);
}
