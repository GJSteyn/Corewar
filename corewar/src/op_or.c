/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:04:34 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/17 12:50:22 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_or(struct s_process *bot)
{
	int		*args;

	// print_op_basics(bot, "or");
	args = bot->args;
	args[0] = (bot->is_reg[0]) ? bot->reg[args[0]] : args[0];
	args[1] = (bot->is_reg[1]) ? bot->reg[args[1]] : args[1];
	bot->reg[args[2]] = args[0] | args[1];
	bot->carry = !(bot->reg[args[2]]);
}
