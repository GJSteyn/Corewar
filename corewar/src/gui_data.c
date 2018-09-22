/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:56:35 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/22 12:38:49 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "corewar.h"
#include "visualiser.h"

#define GUI_X 26
#define GUI_Y EM + 2
#define LIN 40
#define COL 90
#define PL_1X 37
#define PL_1Y GUI_Y
#define PL_2X 37
#define PL_2Y GUI_Y + 45
#define PL_3X 51
#define PL_3Y GUI_Y
#define PL_4X 51
#define PL_4Y GUI_Y + 45

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
	mvprintw(PL_1X + 8, PL_1Y, "Cycle of last live:");
	mvprintw(PL_2X + 4, PL_2Y, "Forks:");
	mvprintw(PL_2X + 6, PL_2Y, "Lives:");
	mvprintw(PL_2X + 8, PL_2Y, "Cycle of last live:");
	mvprintw(PL_3X + 4, PL_3Y, "Forks:");
	mvprintw(PL_3X + 6, PL_3Y, "Lives;");
	mvprintw(PL_3X + 8, PL_3Y, "Cycle of last live:");
	mvprintw(PL_4X + 4, PL_4Y, "Forks:");
	mvprintw(PL_4X + 6, PL_4Y, "Lives:");
	mvprintw(PL_4X + 8, PL_4Y, "Cycle of last live:");
}

void			update_player_data(int player, int fork, int live, int last_l)
{
	if (player == 1)
	{
		mvprintw(PL_1X + 4, PL_1Y + 30, "% 10d", fork);
		mvprintw(PL_1X + 6, PL_1Y + 30, "% 10d", live);
		mvprintw(PL_1X + 8, PL_1Y + 30, "% 10d", last_l);
	}
	else if (player == 2)
	{
		mvprintw(PL_2X + 4, PL_2Y + 30, "% 10d", fork);
		mvprintw(PL_2X + 6, PL_2Y + 30, "% 10d", live);
		mvprintw(PL_2X + 8, PL_2Y + 30, "% 10d", last_l);
	}
	else if (player == 3)
	{
		mvprintw(PL_3X + 4, PL_3Y + 30, "% 10d", fork);
		mvprintw(PL_3X + 6, PL_3Y + 30, "% 10d", live);
		mvprintw(PL_3X + 8, PL_3Y + 30, "% 10d", last_l);
	}
	else
	{
		mvprintw(PL_4X + 4, PL_4Y + 30, "% 10d", fork);
		mvprintw(PL_4X + 6, PL_4Y + 30, "% 10d", live);
		mvprintw(PL_4X + 8, PL_4Y + 30, "% 10d", last_l);
	}
}

void			update_gui_data(int cycledelta, int cycletodie, int process)
{
	mvprintw(GUI_X + 2, GUI_Y + 15, "% 10d", cycledelta);
	mvprintw(GUI_X + 4, GUI_Y + 15, "% 10d", cycletodie);
	mvprintw(GUI_X + 6, GUI_Y + 15, "% 10d", process);
}

void			set_gui_headings(void)
{
	mvprintw(GUI_X, GUI_Y, "AT WAR!");
	mvprintw(GUI_X + 2, GUI_Y, "CYCLE DELTA:");
	mvprintw(GUI_X + 4, GUI_Y, "CYCLE TO DIE:");
	mvprintw(GUI_X + 6, GUI_Y, "PROCESSES:");
	set_champ();
	player_headings();
	refresh();
	update_gui_data(100, 200, 300);
	update_player_data(1, 200, 300, 100000);
	dead(PL_4X, PL_4Y, 4);
	refresh();
}
