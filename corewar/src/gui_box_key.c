/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_box_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:01:12 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/22 16:22:17 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualiser.h"

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

void				key(void)
{
	mvprintw(GUI_X, GUI_Y + 45, "KEY");
	mvprintw(GUI_X + 2, GUI_Y + 45, "%- 20s [%s]", "PAUSE:", "space");
	mvprintw(GUI_X + 4, GUI_Y + 45, "%- 20s [%s]", "QUIT:", "Q");
	mvprintw(GUI_X + 6, GUI_Y + 45, "%- 20s [%s]", "SPEED:", "s] / [f");
}

void				score_box(void)
{
	set_gui_headings();
	wattron(stdscr, COLOR_PAIR(5));
	mvhline(50, EM + 1, 0, 89);
	mvvline(24, EM + 45, 0, 41);
	wattron(stdscr, COLOR_PAIR(6));
	mvhline(2, EM, 0, 90);
	mvhline(65, EM, 0, 90);
	mvvline(2, EM, 0, 64);
	mvvline(2, EM + 90, 0, 64);
	mvhline(35, EM + 1, 0, 89);
	mvhline(24, EM + 1, 0, 89);
	wattroff(stdscr, COLOR_PAIR(6));
	wattroff(stdscr, COLOR_PAIR(5));
	key();
}
