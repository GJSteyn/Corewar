/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:01:12 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/22 11:02:12 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualiser.h"

// #define GUI_X 26
// #define GUI_Y EM + 2
// #define LIN 40
// #define COL 90
// #define PL_1X 37
// #define PL_1Y GUI_Y
// #define PL_2X 37
// #define PL_2Y GUI_Y + 45
// #define PL_3X 51
// #define PL_3Y GUI_Y
// #define PL_4X 51
// #define PL_4Y GUI_Y + 45

// void				set_champ(void)
// {
// 	mvprintw(PL_1X, PL_1Y, "PLAYER ONE:");
// 	mvprintw(PL_1X + 1, PL_1Y, "%.42s", g_env.vis_env.champs[0]);
// 	mvprintw(PL_1X + 2, PL_1Y, "\"%.42s\"", g_env.vis_env.desc[0]);
// 	mvprintw(PL_2X, PL_2Y, "PLAYER TWO:");
// 	mvprintw(PL_2X + 1, PL_2Y, "%.42s", g_env.vis_env.champs[1]);
// 	mvprintw(PL_2X + 2, PL_2Y, "\"%.42s\"", g_env.vis_env.desc[1]);
// 	mvprintw(PL_3X, PL_3Y, "PLAYER THREE:");
// 	mvprintw(PL_3X + 1, PL_3Y, "%.42s", g_env.vis_env.champs[2]);
// 	mvprintw(PL_3X + 2, PL_3Y, "\"%.42s\"", g_env.vis_env.desc[2]);
// 	mvprintw(PL_4X, PL_4Y, "PLAYER FOUR:");
// 	mvprintw(PL_4X + 1, PL_4Y, "%.42s", g_env.vis_env.champs[3]);
// 	mvprintw(PL_4X + 2, PL_4Y, "\"%.42s\"", g_env.vis_env.desc[3]);
// 	refresh();
// }

// void				update_gui_data(int cycledelta, int cycletodie, int process)
// {
// 	mvprintw(GUI_X + 2, GUI_Y + 20, "%d", cycledelta);
// 	mvprintw(GUI_X + 4, GUI_Y + 20, "%d", cycletodie);
// 	mvprintw(GUI_X + 6, GUI_Y + 20, "%d", process);
// }

// void				set_gui_headings(void)
// {
// 	mvprintw(GUI_X, GUI_Y, "AT WAR!");
// 	mvprintw(GUI_X + 2, GUI_Y, "CYCLE DELTA:");
// 	mvprintw(GUI_X + 4, GUI_Y, "CYCLE TO DIE:");
// 	mvprintw(GUI_X + 6, GUI_Y, "PROCESSES:");
// 	set_champ();
// }

void				clear_box(int l, int c, int sl, int sc)
{
	int i;
	int temp;

	temp = sc;
	while (l--)
	{
		i = 0;
		sc = temp;
		while (i <= c)
		{
			mvprintw(sl, sc, " ");
			i++;
			sc++;
		}
		sl++;
	}
}

void				score_box(void)
{
	set_gui_headings();
	update_gui_data(100, 200, 300);
	wattron(stdscr, COLOR_PAIR(6));
	mvhline(2, EM, 0, 90);
	mvhline(65, EM, 0, 90);
	mvvline(2, EM, 0, 64);
	mvvline(2, EM + 90, 0, 64);
	mvhline(35, EM + 1, 0, 89);
	wattron(stdscr, COLOR_PAIR(5));
	mvhline(25, EM + 1, 0, 89);
	mvhline(50, EM + 1, 0, 89);
	mvvline(36, EM + 45, 0, 29);
	wattroff(stdscr, COLOR_PAIR(6));
	wattroff(stdscr, COLOR_PAIR(5));
}
