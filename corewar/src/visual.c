/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:00:07 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/11 07:44:12 by kmarchan         ###   ########.fr       */
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
	c = 2;
	l = 2;
	while (++i < MEM_SIZE)
	{
		if (i % 64 == 0)
		{
			printw("\n");
			c = 2 && l++;
		}
		if (g_env.memory[i] > 0)
		{
			mvprintw(l, c, "%.2hhx", g_env.memory[i]);
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
	// if (vis->img == NULL)
	// {
	// 	get_logo(vis);
	// }
	// initscr();
	print_core();
	print_logo(vis);
	refresh();
	usleep(1000000);
	// endwin();
	return (1);
}
