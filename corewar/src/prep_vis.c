/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_vis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 07:41:32 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/12 07:38:31 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "f_io.h"
#include "f_print.h"

static void				get_logo(t_vis *vis)
{
	char	*file_name;
	int		i;
	char	*line;
	t_file	*file;

	i = 0;
	vis->fl = 22;
	file_name = "corewar_ascii.txt";
	file = f_openf(file_name, 'r');
	vis->img = (char **)f_memalloc(sizeof(char *) * vis->fl);
	while (f_next_line(&line, file))
	{
		vis->img[i++] = f_strdup(line);
		free(line);
	}
	if (line)
		free(line);
	vis->img[i] = NULL;
	f_closef(file);
}

t_vis				*init_vis(void)
{
	t_vis *new;

	new = (t_vis *)f_memalloc(sizeof(t_vis));
	new->img = NULL;
	// new->champs = (char **)f_memalloc(sizeof(char *) * MAX_PLAYERS + 1);
	// new->desc = (char **)f_memalloc(sizeof(char *) * MAX_PLAYERS + 1);
	return (new);
}

void				free_ar(char **ar, int n)
{
	int e;

	e = 0;
	while (e < n)
	{
		free(ar[e]);
		e++;
	}
}

t_vis				*start_vis(void)
{
	t_vis *new;

	new = init_vis();
	get_logo(new);
	initscr();
	curs_set(0);
	wresize(stdscr, 65, 65 * 5);
	return (new);
}

void				end_vis(t_vis **vis)
{
	(void)vis;
	// free_ar((*vis)->champs, MAX_PLAYERS + 1);
	// free_ar((*vis)->desc, MAX_PLAYERS + 1);
	free_ar((*vis)->img, (*vis)->fl);
	endwin();
}
