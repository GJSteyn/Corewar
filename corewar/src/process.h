/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 22:46:08 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/10 09:02:23 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include <stdlib.h>
# include <stdbool.h>

# include "op.h"
# include "list.h"

struct	s_process
{
	int				process_code;
	int				live;
	unsigned int	next_pc;
	bool			carry;
	int				reg[REG_NUMBER];
	int				delay;
	void			(*op)(struct s_process*);
	int				current_pc;
	int				args[MAX_ARGS_NUMBER];
	int				is_reg[MAX_ARGS_NUMBER];
};

struct s_process	*process_create(int pcode, unsigned int pc, bool carry);
void				process_init(struct s_process *process);

#endif
