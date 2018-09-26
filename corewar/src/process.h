/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 22:46:08 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/26 17:51:01 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include <stdlib.h>
# include <stdbool.h>

# include "core.h"
# include "op.h"
# include "list.h"
# include "s_env.h"

struct				s_process
{
	unsigned int	id;
	int				created_by;
	int				live;
	int				next_pc;
	int				current_pc;
	bool			carry;
	int				reg[REG_NUMBER];
	int				delay;
	void			(*op)(struct s_process*);
	int				args[MAX_ARGS_NUMBER];
	int				is_reg[MAX_ARGS_NUMBER];
};

struct s_process	*process_create(int pcode, unsigned int pc, bool carry);
void				process_init(struct s_process *process);

#endif
