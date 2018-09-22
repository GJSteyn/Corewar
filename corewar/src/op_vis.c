/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_vis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:53:59 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/22 13:55:23 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualiser.h"

void			set_vis_mem(int i, char val, int p)
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
	if (val)
		mvprintw(lin, col, "%.2hhx", val);
	else 
		mvprintw(lin, col, "--");
	wattroff(stdscr, WA_BOLD);
	wattroff(stdscr, COLOR_PAIR(p));
}

static void		dead(int offv, int offh, int player_color)
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

static void		victor(int offv, int offh)
{
	int i;

	i = 2;
	wattron(stdscr, COLOR_PAIR(8));
	mvprintw(offv + i++, offh, "         ____                               ");
	mvprintw(offv + i++, offh, "         \\__/                               ");
	mvprintw(offv + i++, offh, "          ||'.\"-._.-\"\"--.-\"-.__.-'/  "
	"       ");
	mvprintw(offv + i++, offh, "          ||  \\       .-.        (          ");
	mvprintw(offv + i++, offh, "          ||   |     (X.X)        )         ");
	mvprintw(offv + i++, offh, "          ||   |   '=.|m|.='     /          ");
	mvprintw(offv + i++, offh, "          ||  /    .='`\"``=.    /           ");
	mvprintw(offv + i++, offh, "          ||.'                 (            ");
	mvprintw(offv + i++, offh, "          ||.-\"-.__.-\"\"-.__.-\"-.)   "
	"        ");
	mvprintw(offv + i++, offh, "          ||                                ");
	mvprintw(offv + i++, offh, "          ||                                ");
	mvprintw(offv + i++, offh, "          ||                                ");
	wattroff(stdscr, COLOR_PAIR(8));
}

void		printf_dead(int player)
{
	int x;
	int y;

	y = (player == 1 || player == 3) ? PL_1Y : PL_2Y;
	x = (player < 3) ? PL_1X : PL_3X;
	dead(x, y, player);
}

void		printf_victor(int player)
{
	int x;
	int y;

	y = (player == 1 || player == 3) ? PL_1Y : PL_2Y;
	x = (player < 3) ? PL_1X : PL_3X;
	victor(x, y);
}
