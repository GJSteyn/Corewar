/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:28:00 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/26 16:41:35 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_add(struct s_process *bot)
{
	int		*args;
	int		*reg;

	args = bot->args;
	reg = bot->reg;
	reg[args[2]] = reg[args[0]] + reg[args[1]];
	bot->carry = !(reg[args[2]]);
}
