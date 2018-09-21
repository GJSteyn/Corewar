/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_vis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 07:41:32 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/21 13:56:11 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualiser.h"
#include "f_io.h"
#include "f_print.h"

// static void			init_vis(void)
// {
// 	g_env.vis_env.img = NULL;
// }

void			start_vis(void)
{
	// init_vis();
	initscr();
	curs_set(0);
}

void			end_vis(void)
{
	curs_set(1);
	endwin();
}
