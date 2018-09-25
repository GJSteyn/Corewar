/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_vis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 07:41:32 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/25 13:10:34 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualiser.h"
#include "f_io.h"
#include "f_print.h"

static void		red_eye(int i, int l, int c)
{
	init_col();
	mvprintw((i + l), (c), "    `9XXXXXXXXXXXP' `9XX'  ");
	wattron(stdscr, COLOR_PAIR(5));
	mvprintw((i + l), (c + 27), "CORE");
	wattroff(stdscr, COLOR_PAIR(5));
	mvprintw((i + l), (c + 31), "    `98v8P'   ");
	wattron(stdscr, COLOR_PAIR(5));
	mvprintw((i + l), (c + 45), "WAR");
	wattroff(stdscr, COLOR_PAIR(5));
	mvprintw((i + l), (c + 48), "   `XXP' `9XXXXXXXXXXXP'");
}

void			print_logoa(int i, int l, int c)
{
	mvprintw((i++ + l), c, "          .                           "
	"                            .");
	mvprintw((i++ + l), c, "        .n                   .         "
	"        .                   n.");
	mvprintw((i++ + l), c, "  .   .dP                  dP          "
	"         9b                  9b.   .");
	mvprintw((i++ + l), c, " 4    qXb         .     . dX           "
	"          Xb .     .         dXp    t");
	mvprintw((i++ + l), c, "dX.   9IXb      .dXb    xx '\"         "
	"           \"' xx    dXb.     dXIP   .Xb");
	mvprintw((i++ + l), c, "9XXb._ \"\"\"\"  _.dXXXXb dXXXXbo.     "
	"            .odXXXXb dXXXXb._  \"\"\"\" _.dXXP");
	mvprintw((i++ + l), c, " 9XXXXXXXXXXXXXXXXXXXVXXXXXXXXOo.      "
	"     .oOXXXXXXXXVXXXXXXXXXXXXXXXXXXXP");
	mvprintw((i++ + l), c, "  `9XXXXXXXXXXXXXXXXXXXXX'~   ~`OOO8b  "
	" d8OOO'~   ~`XXXXXXXXXXXXXXXXXXXXXP'");
}

void			print_logo(int l, int c)
{
	int i;

	i = 0;
	print_logoa(i, l, c);
	i = 8;
	red_eye(i++, l, c);
	mvprintw((i++ + l), c, "       '\"\"\"\"\"\"\"'      9X.       "
	"   .db|db.          .XP    '\"\"\"\"\"\"\"'");
	mvprintw((i++ + l), c, "                        )b.  .dbo.dP'`v"
	"'`9b.odb.  .dX(");
	mvprintw((i++ + l), c, "                      ,dXXXXXXXXXXXb   "
	"  dXXXXXXXXXXXb.");
	mvprintw((i++ + l), c, "                     dXXXXXXXXXXXP'   ."
	"   `9XXXXXXXXXXXb");
	mvprintw((i++ + l), c, "                    dXXXXXXXXXXXXb   d|"
	"b   dXXXXXXXXXXXXb");
	mvprintw((i++ + l), c, "                    9XXb'   `XXXXXb.dX|"
	"Xb.dXXXXX'   `dXXP");
	mvprintw((i++ + l), c, "                     `'      9XXXXXX(  "
	" )XXXXXXP      `'");
	mvprintw((i++ + l), c, "                              XXXX X.`E'.X XXXX");
	mvprintw((i++ + l), c, "                              XP^X'`R   W'`X^XX");
	mvprintw((i++ + l), c, "                              X. O  `   '  A )X");
	mvprintw((i++ + l), c, "                              `C  `       '  R'");
	mvprintw((i++ + l), c, "                               `             '");
}

void			init_vis(void)
{
	f_bzero(g_env.vis_env.player_forks, MAX_PLAYERS);
	f_bzero(g_env.vis_env.player_live, MAX_PLAYERS);
}

void			start_vis(void)
{
	initscr();
	noecho();
	nocbreak();
	timeout(0);
	curs_set(0);
}

void			end_vis(void)
{
	curs_set(1);
	endwin();
}
