/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:01:12 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/18 13:04:59 by kmarchan         ###   ########.fr       */
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

void				score_box(void)
{
	wattron(stdscr, COLOR_PAIR(6));
	mvhline(2, EM, 0, 90);
	mvhline(65, EM, 0, 90);
	mvvline(2, EM, 0, 64);
	mvvline(2, EM + 90, 0, 64);
	wattron(stdscr, COLOR_PAIR(5));
	mvhline(25, EM + 1, 0, 89);
	wattroff(stdscr, COLOR_PAIR(6));
	wattroff(stdscr, COLOR_PAIR(5));
}
