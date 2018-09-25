/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:37:55 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/22 14:49:08 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualiser.h"

static void		scr_instruction(t_vis *vis, int l, int c)
{
	while (vis->m_l < 66 || vis->m_c < EM + 87)
	{
		if (vis->m_l != l || vis->m_c != c)
		{
			wclear(stdscr);
			if (vis->m_l < 66)
			{
				mvvline(0, vis->m_c / 2, 0, vis->m_l);
				mvaddch(vis->m_l / 2 - 1, vis->m_c / 2, ACS_UARROW);
				mvaddch(vis->m_l / 2 + 1, vis->m_c / 2, ACS_DARROW);
			}
			if (vis->m_c < EM + 90)
			{
				mvhline(vis->m_l / 2, 0, 0, vis->m_c);
				mvaddch(vis->m_l / 2, vis->m_c / 2 - 14, ACS_LARROW);
				mvaddch(vis->m_l / 2, vis->m_c / 2 + 14, ACS_RARROW);
			}
			mvprintw(vis->m_l / 2, vis->m_c / 2 - 13, " Please "
			"make window bigger ");
			l = vis->m_l;
			c = vis->m_c;
		}
		refresh();
		getmaxyx(stdscr, vis->m_l, vis->m_c);
	}
}

void			scr_size(void)
{
	int		l;
	int		c;
	t_vis	*vis;

	vis = &g_env.vis_env;
	getmaxyx(stdscr, vis->m_l, vis->m_c);
	l = vis->m_l - 1;
	c = vis->m_c - 1;
	scr_instruction(vis, l, c);
	wclear(stdscr);
	mvprintw(1, EM, "- WSEEGERS GSTEYN PSTUBBS KMARCHAN");
	usleep(150000);
}
