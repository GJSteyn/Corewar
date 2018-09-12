/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:00:07 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/12 14:44:55 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <time.h>
#include "corewar.h"

static void			print_logo(t_vis *vis, int l, int c)
{
	int i;

	i = -1;
	while (vis->img[++i])
	{
		mvprintw((i + l), (c), "%s", vis->img[i]);
	}
}

static void			print_core(void)
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

static void				print_box(int l, int c, int sl, int sc)
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

void					init_col(void)
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_RED);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
}

#define Y_CMAMP 30
#define FOV2	(64 * 3 / 2)

void					champ_intro(t_vis *vis)
{
	int i;
	(void)vis;
	i = 0;
	while (i < MAX_PLAYERS)
	{
		print_box(55, 173, 6, 10);
		print_logo(vis, 7, FOV2 - (77 / 2));
		mvprintw(Y_CMAMP, FOV2 - (96 / 2), "XXXXXX XX  XX XXXXXX      dP"
		"\"\"8b XX  XX    db    Xb    dX XX\"\"Yb XX  dP\"Yb  XXb XX .dP\"YX");
		mvprintw(Y_CHAMP + 1, FOV2 - (96 / 2), "  XX   XX  XX XX__       dP  "
		" `\" XX  XX   dPYb   XXb  dXX XX__dP XX dP   Yb XXYbXX `Ybo. ");
		mvprintw(Y_CHAMP + 2, FOV2 - (96 / 2), "  XX   XXXXXX XX\"\"       Yb  "
		"    XXXXXX  dP__Yb  XXYbdPXX XX\"\"\"  XX Yb   dP XX YXX o.`Y8b");
		mvprintw(Y_CHAMP + 3, FOV2 - (96 / 2), "  XX   XX  XX XXXXXX      Yboo"
		"dP XX  XX dP\"\"\"\"Yb XX YY XX XX     XX  YbodP  XX  YX XbodP'");
		refresh();
		wattron(stdscr, A_BOLD);
		mvprintw(40, FOV2 - (f_strlen(vis->champs[i]) / 2), "%s", vis->champs[i]);
		mvprintw(42, FOV2 - (f_strlen(vis->desc[i]) / 2), "\"%s\"", vis->desc[i]);
		refresh();
		usleep(1500000);
		wattroff(stdscr, A_BOLD);
		i++;
	}
}

void					intro(t_vis *vis)
{
	init_col();
	wattron(stdscr, COLOR_PAIR(1));
	print_core();
	refresh();
	usleep(100000);
	wattroff(stdscr, COLOR_PAIR(1));
	print_box(55, 173, 6, 10);
	refresh();
	champ_intro(vis);
}

int					visualizer(t_vis *vis)
{
	print_core();
	print_logo(vis, 2, 65 * 3);
	refresh();
	usleep(1000000);
	return (1);
}
