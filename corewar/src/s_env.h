/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_env.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:22:01 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/18 14:22:00 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_ENV_H
# define S_ENV_H

# include "op.h"
# include "flag.h"

struct	s_env
{
	char			memory[MEM_SIZE];
	unsigned int	player_total;
	int				last_live;
	unsigned int	next_id;
	t_list			*process_list;
	int				cycles;
	int				live_counter;
	int				cycle_to_die;
	int				delta_count;
	int				last_delta;
	int				flag;
	int				flag_args[FLAG_TOTAL];
};

struct s_env	g_env;

#endif
