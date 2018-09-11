/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:49:09 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/11 14:17:56 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <curses.h>

# include "op.h"
# include "f_string.h"
# include "core.h"
# include "process.h"

struct			s_env
{
	char			memory[MEM_SIZE];
	unsigned int	player_total;
};

struct s_env	g_env;

typedef struct	s_vis
{
	int		process_code;
	int		fl;
	char	**img;
	// char	**champs;
	char	champs[4][PROG_NAME_LENGTH];
	// char	**desc;
	char	desc[4][COMMENT_LENGTH];
}				t_vis;

# define PLAYER_POS(nbr, total)	(((MEM_SIZE / total) * (nbr - 1)))

int			visualizer(t_vis *vis);
t_vis		*init_vis();
t_vis		*start_vis(void);
void		end_vis(t_vis **vis);


#endif
