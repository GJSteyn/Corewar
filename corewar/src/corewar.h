/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:49:09 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/04 21:49:33 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>

# include "op.h"

struct	s_env
{
	char			memory[MEM_SIZE];
	unsigned int	player_total;
};

struct	s_process
{
	int				process_code;
	unsigned int	pc;
	bool			carry;
	unsigned int	delay;
	void			(*op)(int args[4]);
	int				args[MAX_ARGS_NUMBER];
};

struct s_env	*g_env;

# define PLAYER_POS(player_no, total)	((MEM_SIZE / total) * player_no)


#endif
