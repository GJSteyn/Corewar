/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 10:55:41 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/17 12:51:00 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_zjmp(struct s_process *bot)
{
	// print_op_basics(bot, "zjmp");
	if (bot->carry)
	{
		// f_printf("-----> Success (%d)\n", bot->args[0]);
		bot->next_pc = WRAP_MEM(bot->current_pc + (bot->args[0] % IDX_MOD));
	}
	// else
		// f_printf("-----> Fail\n");
}
