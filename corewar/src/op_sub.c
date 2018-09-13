/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:59:31 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/12 13:56:12 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_sub(struct s_process *bot)
{
	int		*args;
	int		*reg;

	print_op_basics(bot, "sub");
	args = bot->args;
	reg = bot->reg;
	reg[args[2]] = reg[args[0]] - reg[args[1]];
	bot->carry = !(reg[args[2]]);
}
