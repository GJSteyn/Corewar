/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_vis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:53:59 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/18 14:11:36 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualiser.h"

		// set_vis_mem(WRAP(offset), big_e[0], g_env->vis->owners[bot->current_pc]);

void		set_vis_mem(int i, char val, int p)
{
	int lin;
	int col;

	lin = 2;
	col = 1;
	wattron(stdscr, COLOR_PAIR(p));
	if (p >= 10)
		wattron(stdscr, WA_BOLD);
	lin += i / 64;
	col += (i % 64) * 3;
	mvprintw(lin, col, "%.2hhx", val);
	wattroff(stdscr, WA_BOLD);
	wattroff(stdscr, COLOR_PAIR(p));
}
