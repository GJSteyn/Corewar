/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:09:15 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/26 16:34:44 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

typedef struct s_process	t_process;

static void	init_env(void)
{
	f_bzero(g_env.memory, MEM_SIZE);
	f_bzero(g_env.flag_args, FLAG_TOTAL * 4);
	g_env.player_total = 4;
	g_env.last_live = 0;
	g_env.next_id = 1;
	g_env.process_list = list_create(free);
	g_env.cycles = 1;
	g_env.live_counter = 0;
	g_env.cycle_to_die = CYCLE_TO_DIE;
	g_env.last_delta = 0;
	g_env.delta_count = 0;
	g_env.pause = false;
	g_env.flag = 0;
	g_env.flag_args[FLAG_MEM_DUMP] = INT_MAX;
}

int			main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	init_env();
	handle_args(argc, argv);
	if (!g_env.player_total)
		fatal("No Players found!\n");
	if (IS_FLAG_SET(FLAG_NCURSES))
	{
		start_vis();
		scr_size();
		if (!IS_FLAG_SET(FLAG_NO_INTRO))
			intro();
		visualizer();
		battle_loop_vis();
		end_vis();
	}
	else
	{
		battle_loop();
		f_printf("last_live-> %d\n", g_env.last_live);
		f_printf("cycles: %d\n", g_env.cycles);
	}
}
