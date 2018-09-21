/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_function.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:17:31 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/21 07:14:18 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP
# define OP_FUNCTION_H

# include <stdlib.h>

# include "core.h"
# include "op.h"
# include "process.h"
# include "f_print.h"
# include "s_env.h"
# include "visualiser.h"

# define HAS_ENCODE(op) 	(g_op_tab[op].has_encoding)
# define IS_INDEX(op)		(g_op_tab[op].direct_index)

# define TYPE_MAP(arg_type)	((int[4]){0, T_REG, T_DIR, T_IND}[arg_type])
# define TYPE_BYTES(type)	((int[5]){0, 1, DIR_SIZE, 2, IND_SIZE}[type])
# define DECODE(enc, n)		(TYPE_MAP(enc >> ((3 - n) * 2) & 3))

# define WRAP_MEM(n)		((MEM_SIZE + ((n) % MEM_SIZE)) % MEM_SIZE)
# define WRAP_IDX(n)		((n) % IDX_MOD)

void 	(*op_function(int i))(struct s_process*);

void	get_next_op(struct s_process *bot);

void	op_live(struct s_process *bot);
void	op_ld(struct s_process *bot);
void	op_st(struct s_process *bot);
void	op_add(struct s_process *bot);
void	op_sub(struct s_process *bot);
void	op_and(struct s_process *bot);
void	op_or(struct s_process *bot);
void	op_xor(struct s_process *bot);
void	op_zjmp(struct s_process *bot);
void	op_ldi(struct s_process *bot);
void	op_sti(struct s_process *bot);
void	op_fork(struct s_process *bot);
void	op_lldi(struct s_process *bot);
void	op_lfork(struct s_process *bot);
void	op_aff(struct s_process *bot);

void	op_st_vis(struct s_process *bot);
void	op_sti_vis(struct s_process *bot);

// debugging
void	print_memory(void);
void	print_bot(struct s_process *bot);
void	print_op_basics(struct s_process *bot, char *op);
#endif
