/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_function.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:17:31 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/09 19:43:45 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP
# define OP_FUNCTION_H

# include <stdlib.h>

# include "op.h"
# include "process.h"
# include "f_print.h"

# define HAS_ENCODE(op) 	(g_op_tab[op].has_encoding)
# define IS_INDEX(op)		(g_op_tab[op].direct_index)

# define TYPE_MAP(arg_type)	((int[4]){0, T_REG, T_DIR, T_IND}[arg_type])
# define DECODE(enc, n)		(TYPE_MAP(enc >> ((3 - n) * 2) & 3))

# define WRAP_MEM(n)		((n) % MEM_SIZE)

void 	(*op_function(int i))(struct s_process*);

void	op_live(struct s_process *bot);

#endif
