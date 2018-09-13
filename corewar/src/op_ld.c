/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:03:37 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/13 16:45:11 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_ld(struct s_process *bot)
{
	int		*args;

	print_op_basics(bot, "ld");
	args = bot->args;
	f_printf("%d -> r%d\n", args[0], args[1] + 1);
	bot->reg[args[1]] = args[0];
	bot->carry = !(args[0]);
}
