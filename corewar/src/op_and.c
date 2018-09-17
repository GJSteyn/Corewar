/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:39:52 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/17 12:49:29 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_and(struct s_process *bot)
{
	int		*args;

	// print_op_basics(bot, "and");
	args = bot->args;
	args[0] = (bot->is_reg[0]) ? bot->reg[args[0]] : args[0];
	args[1] = (bot->is_reg[1]) ? bot->reg[args[1]] : args[1];
	bot->reg[args[2]] = args[0] & args[1];
	bot->carry = !(bot->reg[args[2]]);
}
