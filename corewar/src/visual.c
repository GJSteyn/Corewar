/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:00:07 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/21 13:52:59 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualiser.h"

void				init_col(void)
{
	start_color();
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_RED);
	init_pair(10, COLOR_WHITE, COLOR_WHITE);
	init_pair(11, COLOR_RED, COLOR_RED);
	init_pair(12, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(13, COLOR_GREEN, COLOR_GREEN);
	init_pair(14, COLOR_CYAN, COLOR_CYAN);
}

static void			red_eye(int i, int l, int c)
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

void				print_logoa(int i, int l, int c)
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

void				print_logo(int l, int c)
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
	print_logo(3, 65 * 3 + 7);
	score_box();
	refresh();
	// usleep(1000000);
	return (1);
}

