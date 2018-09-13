/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:00:07 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/13 12:03:22 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <time.h>
#include "corewar.h"

void					init_col(void)
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
}

static void			red_eye(int i, int l, int c)
{
	init_col();
	mvprintw((i + l), (c), "    `9XXXXXXXXXXXP' `9XX'  ");
	wattron(stdscr, COLOR_PAIR(1));
	mvprintw((i + l), (c + 27), "CORE");
	wattroff(stdscr, COLOR_PAIR(1));
	mvprintw((i + l), (c + 31), "    `98v8P'   ");
	wattron(stdscr, COLOR_PAIR(1));
	mvprintw((i + l), (c + 45), "WAR");
	wattroff(stdscr, COLOR_PAIR(1));
	mvprintw((i + l), (c + 48), "   `XXP' `9XXXXXXXXXXXP'");
}

static void			print_logo(t_vis *vis, int l, int c)
{
	int i;

	i = -1;
	while (vis->img[++i])
	{
		if (i == 8)
			red_eye(i, l, c);
		else
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

void					champ_intro(t_vis *vis)
{
	int i;
	(void)vis;
	i = 0;
	print_box(55, 173, 6, 10);
	print_logo(vis, 7, FOV2 - (77 / 2));
	the_corewar();
	while (i < MAX_PLAYERS)
	{
		print_box(55, 173, 6, 10);
		print_logo(vis, 7, FOV2 - (77 / 2));
		the_champions();
		wattron(stdscr, A_BOLD);
		mvprintw(40, FOV2 - (f_strlen(vis->champs[i]) / 2), "%s", vis->champs[i]);
		mvprintw(42, FOV2 - (f_strlen(vis->desc[i]) / 2), "\"%s\"", vis->desc[i]);
		refresh();
		usleep(1500000);
		wattroff(stdscr, A_BOLD);
		i++;
	}
	print_box(55, 173, 6, 10);
	print_logo(vis, 7, FOV2 - (77 / 2));
	ready();
	print_box(55, 173, 6, 10);
	print_logo(vis, 7, FOV2 - (77 / 2));
	set();
	charge();
	refresh();
	usleep(1500000);
}

void					intro(t_vis *vis)
{
	init_col();
	wattron(stdscr, COLOR_PAIR(1));
	// wattron(stdscr, A_BOLD);
	print_core();
	refresh();
	usleep(100000);
	wattroff(stdscr, COLOR_PAIR(1));
	// wattroff(stdscr, A_BOLD);
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
