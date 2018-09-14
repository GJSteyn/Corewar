/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:01:12 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/14 14:19:35 by kmarchan         ###   ########.fr       */
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
	// authors();
}

void				score_box(void)
{
	// int y;

	// y = (65 * 3);
	wattron(stdscr, COLOR_PAIR(2));
	mvhline(2, EM, 0, 90);
	mvhline(65, EM, 0, 90);
	mvvline(2, EM, 0, 64);
	mvvline(2, EM + 90, 0, 64);
	wattron(stdscr, COLOR_PAIR(1));
	box(stdscr, 0, 0);
	mvhline(25, EM + 1, 0, 89);
	wattroff(stdscr, COLOR_PAIR(2));
	wattroff(stdscr, COLOR_PAIR(1));
}
