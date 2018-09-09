/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:11:51 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/09 10:23:50 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void (*op_function(int op_code))(struct s_process*)
{
	static void (*op[MAX_OP + 1])(struct s_process*);

	if (!op[1])
	{
		op[1] = op_live;
	}
	if (!op_code || op_code > MAX_OP)
	{
		f_fprintf(STDERR, "op_funtion : value passed is out of range\n");
		exit(0);
	}
	return (op[op_code]);
}