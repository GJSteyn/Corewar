/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 09:17:22 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/22 12:38:02 by kmarchan         ###   ########.fr       */
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

# define GET_OWNER(pos)			(g_env.vis_env.owner[pos])
# define SET_OWNER(pos, owner)	(GET_OWNER(pos) = owner)
# define GET_MEM(pos)			(g_env.memory[pos])
# define TO_PC(player)			(player + COLOR_BACKGROUND)
# define PAINT_MEM(val, pos)	(set_vis_mem(pos, val, GET_OWNER(pos)))
# define PAINT_PC(val, pos)		(set_vis_mem(pos, val, TO_PC(GET_OWNER(pos))))

# define SET_VIS_MEM(pos, val, owner) {SET_OWNER(pos,owner);PAINT_MEM(val,pos);}

void			ready(void);
void			set(void);
void			charge(void);
void			the_corewar(void);
void			the_champions(void);
void			authors(void);
void			clear_box(int l, int c, int sl, int sc);
void			print_logo(int l, int c);
int				visualizer(void);
void			start_vis(void);
void			end_vis(void);
void			intro(void);
void			print_core(int offh, int offv);
void			init_col(void);
void			score_box(void);
void			set_gui_headings(void);
void			update_gui_data(int cycledelta, int cycletodie, int process);
void			scr_size(void);
void			set_vis_mem(int position, char val, int colour);
void			dead(int offv, int offh, int player_color);

#endif
