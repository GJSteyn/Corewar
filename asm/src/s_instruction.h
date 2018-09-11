/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_instruction.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 09:20:44 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/11 13:46:29 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_INSTRUCTION_H
# define S_INSTRUCTION_H

# include "op.h"
# include "e_type.h"

struct	s_instruction
{
	enum e_op		op;
	enum e_arg_code arg_type[MAX_ARGS_NUMBER];
	int				arg_value[MAX_ARGS_NUMBER];
};

#endif
