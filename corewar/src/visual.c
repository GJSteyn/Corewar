/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:00:07 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/11 14:06:50 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <time.h>
#include "corewar.h"

static void			print_logo(t_vis *vis)
{
	int i;

	i = -1;
	while (vis->img[++i])
	{
		mvprintw((i + 2), (65 * 3), "%s\n", vis->img[i]);
	}
}

static void			print_core(void)
{
	int l;
	int c;
	int i;

	i = -1;
	c = 3;
	l = 1;
	while (++i < MEM_SIZE)
	{
		if (i % 64 == 0)
		{
			printw("\n");
			c = 3 && l++;
		}
		if (g_env.memory[i] > 0)
		{
			mvprintw(l, c, "%.2hhx ", g_env.memory[i]);
			c += 3;
		}
		else
		{
			mvprintw(l, c, "__ ");
			c += 3;
		}
	}
}

void					intro(t_vis *vis)
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_RED);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
	wattron(stdscr, COLOR_PAIR(1));
	// visualizer(vis);
	print_core();
	wattroff(stdscr, COLOR_PAIR(1));
	print_logo(vis);
	int n = 6;
	while (n--)
	mvprintw(20, 64, "                                                               ");
	mvprintw(21, 64, "                       PLAYER \"NAME\"                           ");
	mvprintw(22, 64, "                                                               ");
	refresh();
	usleep(1000000);
}

int					visualizer(t_vis *vis)
{
	print_core();
	print_logo(vis);
	refresh();
	usleep(1000000);
	return (1);
}
