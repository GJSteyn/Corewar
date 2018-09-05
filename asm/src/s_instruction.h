/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_instruction.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 09:20:44 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/05 05:24:27 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "e_type.h"

struct	s_instruction
{
	enum e_op		op;
	enum e_arg_code arg_type[MAX_ARGS_NUMBER];
	int				arg_value[MAX_ARGS_NUMBER];
};


/*

1
[0]op = 11
type = {reg, indirect, dir } &(arg_value[2]) 0 live
val = {1,  <15> , 1}

[9]op = 6
type = {reg, dir, reg}
val = {1, 0, 1}

live:
[15]op = 1
type = {dir, 0, 0}
val = {1, 0, 0}

[21]op = 20
type = {dir}
val = {<-5>}

*/