/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_vis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:53:59 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/22 12:40:13 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualiser.h"

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

void		dead(int offv, int offh, int player_color)
{
	int i;

	i = 2;
	wattron(stdscr, COLOR_PAIR(player_color));
	mvprintw(offv + i++, offh, "            _                   _           ");
	mvprintw(offv + i++, offh, "          _( )      _____      ( )_         ");
	mvprintw(offv + i++, offh, "         (_,  \\    /     \\    /  ,_)   "
	"     ");
	mvprintw(offv + i++, offh, "             '\'\\,/        \\,/'/'      "
	"      ");
	mvprintw(offv + i++, offh, "               '\\| {X} {X} |/'              ");
	mvprintw(offv + i++, offh, "                 (_  /^\\  _)                ");
	mvprintw(offv + i++, offh, "                   /HHHHH\\              "
	"    ");
	mvprintw(offv + i++, offh, "              _,/'/\\ ___ /\\'\\,_       "
	"     ");
	mvprintw(offv + i++, offh, "            (_, /           \\ ,_)           ");
	mvprintw(offv + i++, offh, "              (_)           (_)             ");
	wattroff(stdscr, COLOR_PAIR(player_color));
}
