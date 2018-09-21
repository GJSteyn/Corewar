/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_vis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 07:41:32 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/21 11:08:29 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualiser.h"
#include "f_io.h"
#include "f_print.h"

static void			get_logo(void)
{
	char	*file_name;
	int		i;
	char	*line;
	t_file	*file;

	i = 0;
	file_name = "resources/corewar_ascii.txt";
	file = f_openf(file_name, 'r');
	g_env.vis_env.img = (char **)f_memalloc(sizeof(char *) * ASCII_DEMON_ROWS);
	while (f_next_line(&line, file))
	{
		g_env.vis_env.img[i++] = f_strdup(line);
		free(line);
	}
	free(line);
	g_env.vis_env.img[i] = NULL;
	f_closef(file);
}

static void			init_vis(void)
{
	g_env.vis_env.img = NULL;
}

void			start_vis(void)
{
	init_vis();
	get_logo();
	initscr();
	noecho();
	nocbreak();
	timeout(1);
	curs_set(0);
}

void			end_vis(void)
{
	curs_set(1);
	endwin();
}
