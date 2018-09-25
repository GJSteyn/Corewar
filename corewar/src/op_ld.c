/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:03:37 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/25 07:55:17 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_ld(struct s_process *bot)
{
	int		*args;

	args = bot->args;
	bot->reg[args[1]] = args[0];
	bot->carry = !(args[0]);
}

void	op_ld_verb(struct s_process *bot)
{
	int		*args;

	args = bot->args;
	bot->reg[args[1]] = args[0];
	bot->carry = !(args[0]);
	START_VERB(
		PRINT_PROCESS("ld");
		PRINT_ARG(args[0]);
		PRINT_REG(args[1] + 1);
		PRINT_ENDL;
	)
}
