/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 09:17:22 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/18 14:08:32 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALISER_H
# define VISUALISER_H

# include <time.h>
# include <curses.h>
# include "corewar.h"

# define Y_CHAMP 30
# define FOV2	(64 * 3 / 2)
# define EM	(64 * 3 + 1)
#define COLOR_BACKGROUND	10

typedef struct	s_vis
{
	int		m_l;
	int		m_c;
	int		process_code;
	int		fl;
	char	**img;
	char	champs[4][PROG_NAME_LENGTH];
	char	desc[4][COMMENT_LENGTH];
	char	owner[MEM_SIZE];
}				t_vis;

void			ready(void);
void			set(void);
void			charge(void);
void			the_corewar(void);
void			the_champions(void);
void			authors(void);
void			clear_box(int l, int c, int sl, int sc);
void			print_logo(t_vis *vis, int l, int c);
int				visualizer(t_vis *vis);
t_vis			*init_vis();
t_vis			*start_vis(void);
void			end_vis(t_vis **vis);
void			intro(t_vis *vis);
void			print_core(int offh, int offv);
void			init_col(void);
void			score_box(void);
void			scr_size(t_vis *vis);
void		set_vis_mem(int i, char val, int p);

#endif
