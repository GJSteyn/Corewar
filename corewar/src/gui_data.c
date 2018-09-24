/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:56:35 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/24 13:21:31 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "corewar.h"
#include "visualiser.h"

static void		set_champ(void)
{
	init_col();
	mvprintw(PL_1X, PL_1Y, "PLAYER ONE:");
	wattron(stdscr, COLOR_PAIR(1));
	mvprintw(PL_1X + 1, PL_1Y, "%.42s", g_env.vis_env.champs[0]);
	wattroff(stdscr, COLOR_PAIR(1));
	attron(WA_DIM);
	mvprintw(PL_1X + 2, PL_1Y, "\"%.42s\"", g_env.vis_env.desc[0]);
	attroff(WA_DIM);
	mvprintw(PL_2X, PL_2Y, "PLAYER TWO:");
	wattron(stdscr, COLOR_PAIR(2));
	mvprintw(PL_2X + 1, PL_2Y, "%.42s", g_env.vis_env.champs[1]);
	wattroff(stdscr, COLOR_PAIR(2));
	mvprintw(PL_2X + 2, PL_2Y, "\"%.42s\"", g_env.vis_env.desc[1]);
	mvprintw(PL_3X, PL_3Y, "PLAYER THREE:");
	wattron(stdscr, COLOR_PAIR(3));
	mvprintw(PL_3X + 1, PL_3Y, "%.42s", g_env.vis_env.champs[2]);
	wattroff(stdscr, COLOR_PAIR(3));
	mvprintw(PL_3X + 2, PL_3Y, "\"%.42s\"", g_env.vis_env.desc[2]);
	mvprintw(PL_4X, PL_4Y, "PLAYER FOUR:");
	wattron(stdscr, COLOR_PAIR(4));
	mvprintw(PL_4X + 1, PL_4Y, "%.42s", g_env.vis_env.champs[3]);
	wattroff(stdscr, COLOR_PAIR(4));
	mvprintw(PL_4X + 2, PL_4Y, "\"%.42s\"", g_env.vis_env.desc[3]);
}

static void		player_headings(void)
{
	mvprintw(PL_1X + 4, PL_1Y, "Forks:");
	mvprintw(PL_1X + 6, PL_1Y, "Lives:");
	mvprintw(PL_1X + 8, PL_1Y, "Last live:");
	mvprintw(PL_2X + 4, PL_2Y, "Forks:");
	mvprintw(PL_2X + 6, PL_2Y, "Lives:");
	mvprintw(PL_2X + 8, PL_2Y, "Last live:");
	mvprintw(PL_3X + 4, PL_3Y, "Forks:");
	mvprintw(PL_3X + 6, PL_3Y, "Lives;");
	mvprintw(PL_3X + 8, PL_3Y, "Last live:");
	mvprintw(PL_4X + 4, PL_4Y, "Forks:");
	mvprintw(PL_4X + 6, PL_4Y, "Lives:");
	mvprintw(PL_4X + 8, PL_4Y, "Last live:");
}

void			update_player_data(int player, int last_l) // int fork, int live,
{
	// (void)fork;
	// (void)live;
	if (player == 1)
	{
		mvprintw(PL_1X + 4, PL_1Y + 30, "% 10d", g_env.vis_env.player_forks[0]);
		mvprintw(PL_1X + 6, PL_1Y + 30, "% 10d", g_env.vis_env.player_live[0]);
		mvprintw(PL_1X + 8, PL_1Y + 30, "% 10d", last_l);
	}
	else if (player == 2)
	{
		mvprintw(PL_2X + 4, PL_2Y + 30, "% 10d", g_env.vis_env.player_forks[1]);
		mvprintw(PL_2X + 6, PL_2Y + 30, "% 10d", g_env.vis_env.player_live[1]);
		mvprintw(PL_2X + 8, PL_2Y + 30, "% 10d", last_l);
	}
	else if (player == 3)
	{
		mvprintw(PL_3X + 4, PL_3Y + 30, "% 10d", g_env.vis_env.player_forks[2]);
		mvprintw(PL_3X + 6, PL_3Y + 30, "% 10d", g_env.vis_env.player_live[2]);
		mvprintw(PL_3X + 8, PL_3Y + 30, "% 10d", last_l);
	}
	else
	{
		mvprintw(PL_4X + 4, PL_4Y + 30, "% 10d", g_env.vis_env.player_forks[3]);
		mvprintw(PL_4X + 6, PL_4Y + 30, "% 10d", g_env.vis_env.player_live[3]);
		mvprintw(PL_4X + 8, PL_4Y + 30, "% 10d", last_l);
	}
}

void			update_gui_data(void)
{
	mvprintw(GUI_X + 2, GUI_Y + 30, "% 10d", g_env.cycles);
	mvprintw(GUI_X + 4, GUI_Y + 27, "% 5d / % 5d", g_env.cycle_to_die,
	CYCLE_TO_DIE - g_env.delta_count * CYCLE_DELTA);
	mvprintw(GUI_X + 6, GUI_Y + 30, "% 10d", g_env.process_list->size);
}

void			set_gui_headings(void)
{
	mvprintw(GUI_X, GUI_Y, "AT WAR!");
	mvprintw(GUI_X + 2, GUI_Y, "CYCLE NUMBER:");
	mvprintw(GUI_X + 4, GUI_Y, "CYCLE TO DIE:");
	mvprintw(GUI_X + 6, GUI_Y, "PROCESSES:");
	set_champ();
	player_headings();
	refresh();
	update_gui_data();
	// update_player_data(1, 200, 300, 100000);
	// update_player_data(1, 200, 300, 100000);
	// printf_victor(3);
	// printf_dead(2);
	// printf_dead(1);
	// printf_dead(4);
	// refresh();
}
