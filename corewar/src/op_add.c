/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:28:00 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/17 12:49:24 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_add(struct s_process *bot)
{
	int		*args;
	int		*reg;

	// print_op_basics(bot, "add");
	args = bot->args;
	reg = bot->reg;
	reg[args[2]] = reg[args[0]] + reg[args[1]];
	bot->carry = !(reg[args[2]]);
}
