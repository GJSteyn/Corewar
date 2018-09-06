/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:49:09 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/06 16:16:56 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "op.h"
# include "f_string.h"
# include "core.h"
# include "process.h"

struct	s_env
{
	char			memory[MEM_SIZE];
	unsigned int	player_total;
};

struct s_env	g_env;

# define PLAYER_POS(nbr, total)	(((MEM_SIZE / total) * (nbr - 1)))

#endif
