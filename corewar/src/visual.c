/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:00:07 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/14 11:31:11 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualiser.h"

void				init_col(void)
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
}

static void			red_eye(int i, int l, int c)
{
	init_col();
	mvprintw((i + l), (c), "    `9XXXXXXXXXXXP' `9XX'  ");
	wattron(stdscr, COLOR_PAIR(1));
	mvprintw((i + l), (c + 27), "CORE");
	wattroff(stdscr, COLOR_PAIR(1));
	mvprintw((i + l), (c + 31), "    `98v8P'   ");
	wattron(stdscr, COLOR_PAIR(1));
	mvprintw((i + l), (c + 45), "WAR");
	wattroff(stdscr, COLOR_PAIR(1));
	mvprintw((i + l), (c + 48), "   `XXP' `9XXXXXXXXXXXP'");
}

void				print_logo(t_vis *vis, int l, int c)
{
	int i;

	i = -1;
	while (vis->img[++i])
	{
		if (i == 8)
			red_eye(i, l, c);
		else
			mvprintw((i + l), (c), "%s", vis->img[i]);
	}
}

void				print_core(void)
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

int					visualizer(t_vis *vis)
{
	print_core();
	print_logo(vis, 2, 65 * 3);
	refresh();
	usleep(1000000);
	return (1);
}
