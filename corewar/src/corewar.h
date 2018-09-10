/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:49:09 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/10 08:22:53 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "op.h"
# include "s_op.h"
# include "core.h"
# include "process.h"
# include "op_function.h"
# include "s_env.h"

struct s_env	g_env;

# define PLAYER_POS(nbr, total)	(((MEM_SIZE / total) * (nbr - 1)))

struct s_process	*load_bot(char *path, int player_no);


//debug ulti to be removed
void	print_memory(void);
void	print_bot(struct s_process *bot);

#endif
