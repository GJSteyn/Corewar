/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 09:17:22 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/26 14:13:03 by gsteyn           ###   ########.fr       */
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
# define GUI_X 26
# define GUI_Y EM + 2
# define LIN 40
# define COL 90
# define PL_1X 37
# define PL_1Y GUI_Y
# define PL_2X 37
# define PL_2Y GUI_Y + 45
# define PL_3X 51
# define PL_3Y GUI_Y
# define PL_4X 51
# define PL_4Y GUI_Y + 45

# define GET_OWNER(pos)			(g_env.vis_env.owner[pos])
# define SET_OWNER(pos, owner)	(GET_OWNER(pos) = owner)
# define GET_MEM(pos)			(g_env.memory[pos])
# define TO_PC(player)			(player + COLOR_BACKGROUND)
# define PAINT_MEM(val, pos)	(set_vis_mem(pos, val, GET_OWNER(pos)))
# define PAINT_PC(val, pos)		(set_vis_mem(pos, val, TO_PC(GET_OWNER(pos))))

# define INPUT_CHECK_DELAY	(5)
# define CHECK_INPUT(n) if (!--check_key&&(check_key = n))handle_key_press();
# define FUNNY_IF if (24 == 24)

# define SET_VIS_MEM(pos, val, owner) {SET_OWNER(pos,owner);PAINT_MEM(val,pos);}

# define PAUSE	(g_env.pause = !g_env.pause)

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
void			update_gui_data(void);
void			update_player_data(void);
void			scr_size(void);
void			set_vis_mem(int position, char val, int colour);
void			printf_dead(int player);
void			printf_victor(int player);
void			vm_sound(void);

#endif
