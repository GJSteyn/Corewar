/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:00:07 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/09 15:22:56 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <time.h>
#include "f_io.h"
#include "f_print.h"
#include "corewar.h"

static void			get_logo(t_vis *vis)
{
	char	*file_name;
	char	mode;
	int		i;
	char	*line;
	t_file	*file;

	i = 0;

	mode = 'r';
	file_name = "corewar_ascii.txt";
	file = f_openf(file_name, mode);
	vis->img = (char **)f_memalloc(sizeof(char *) * 22);

	while (f_next_line(&line, file))
	{
		vis->img[i++] = f_strdup(line);
		free(line);
	}
	vis->img[i] = NULL;
	f_closef(file);
}

static void			print_logo(t_vis *vis)
{
	int i;

	i = -1;
	while (vis->img[++i])
	{
		mvprintw((i + 2), (65 * 3), "%s\n", vis->img[i]);
	}
}

t_vis				*init_vis(void)
{
	t_vis *new;

	new = (t_vis *)f_memalloc(sizeof(t_vis));
	new->img = NULL;
	new->champs = (char **)f_memalloc(sizeof(char *) * MAX_PLAYERS + 1);
	new->desc = (char **)f_memalloc(sizeof(char *) * MAX_PLAYERS + 1);
	return (new);
}

static void			print_core(void)
{
	int l;
	int c;
	int i;

	i = -1;
	c = 2;
	l = 2;
	while (++i < MEM_SIZE)
	{
		if (i % 64 == 0)
		{
			printw("\n");
			c = 2 && l++;
		}
		if (g_env.memory[i] > 0)
		{
			mvprintw(l, c, "%.2hhx", g_env.memory[i]);
			c += 3;
		}
		else
		{
			mvprintw(l, c, "__ ");
			c += 3;
		}
	}
}

int					visualizer(t_vis *vis)
{
	if (vis->img == NULL)
	{
		get_logo(vis);
	}
	initscr();
	print_core();
	print_logo(vis);
	refresh();
	usleep(100000000);
	endwin();
	return (1);
}
