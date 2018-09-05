/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 22:46:08 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/05 02:06:19 by wseegers         ###   ########.fr       */
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
	unsigned int	pc;
	bool			carry;
	int				reg[REG_NUMBER];
	unsigned int	delay;
	unsigned int	(*op)(t_process*);
	int				args[MAX_ARGS_NUMBER];
};

struct s_process	*process_create(int pcode, unsigned int pc, bool carry);
void				process_init(struct s_process *process);

#endif
