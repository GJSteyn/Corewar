/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:00:07 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/22 16:13:42 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualiser.h"

void				init_col(void)
{
	start_color();
	init_color(COLOR_BLUE, 1000, 0, 0);
	init_color(COLOR_RED, 1000, 200, 0);
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_RED);
	init_pair(8, COLOR_YELLOW, COLOR_BLACK);
	init_pair(10, COLOR_WHITE, COLOR_WHITE);
	init_pair(11, COLOR_RED, COLOR_BLUE);
	init_pair(12, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(13, COLOR_GREEN, COLOR_GREEN);
	init_pair(14, COLOR_CYAN, COLOR_CYAN);
}

void				print_core(int offh, int offv)
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
			c = 3 && l++;
		}
		if (g_env.memory[i] > 0)
		{
			mvprintw(l + offv, c + offh, "%.2hhx ", g_env.memory[i]);
			c += 3;
		}
		else
		{
			mvprintw(l + offv, c + offh, "-- ");
			c += 3;
		}
	}
}

int					visualizer(void)
{
	t_vis *vis;

	vis = &g_env.vis_env;
	score_box();
	print_core(0, 0);
	print_logo(3, 65 * 3 + 5);
	score_box();
	refresh();
	return (1);
}
