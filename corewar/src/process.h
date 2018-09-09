/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 22:46:08 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/09 20:38:14 by wseegers         ###   ########.fr       */
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
	void			(*op)(struct s_process*);
	int				args[MAX_ARGS_NUMBER];
};

struct s_process	*process_create(int pcode, unsigned int pc, bool carry);
void				process_init(struct s_process *process);

#endif
