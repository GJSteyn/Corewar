/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_env.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:22:01 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/11 13:45:04 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_ENV_H
# define S_ENV_H

# include "op.h"

struct	s_env
{
	char			memory[MEM_SIZE];
	unsigned int	player_total;
	int				last_live;
	t_list			*process_list;
	int				cycles;
	int				live_counter;
	int				cycle_to_die;
	int				delta_count;
	int				last_delta;
};

#endif
