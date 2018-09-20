/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 09:17:22 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/20 11:18:30 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALISER_H
# define VISUALISER_H

# include <time.h>
# include <curses.h>
# include "corewar.h"
# include "s_vis.h"

# define Y_CHAMP 30
# define FOV2	(64 * 3 / 2)
# define EM	(64 * 3 + 1)
# define COLOR_BACKGROUND	10
# define ASCII_DEMON_ROWS	22

void			ready(void);
void			set(void);
void			charge(void);
void			the_corewar(void);
void			the_champions(void);
void			authors(void);
void			clear_box(int l, int c, int sl, int sc);
void			print_logo(t_vis *vis, int l, int c);
int				visualizer(void);
void			start_vis(void);
void			end_vis(void);
void			intro(void);
void			print_core(int offh, int offv);
void			init_col(void);
void			score_box(void);
void			scr_size(void);
void			set_vis_mem(int i, char val, int p);

#endif
