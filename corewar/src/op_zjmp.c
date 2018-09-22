/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 10:55:41 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/22 16:06:13 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_zjmp(struct s_process *bot)
{
	if (bot->carry)
		bot->next_pc = WRAP_MEM(bot->current_pc + (bot->args[0] % IDX_MOD));
}

void	op_zjmp_verb(struct s_process *bot)
{
	if (bot->carry)
	{
		START_VERB(
		PRINT_PROCESS("zjmp");
		PRINT_ARG0;
		PRINT_OK;
		PRINT_ENDL;)
		bot->next_pc = WRAP_MEM(bot->current_pc + (bot->args[0] % IDX_MOD));
	}
	else
		START_VERB(PRINT_FAIL)
}
