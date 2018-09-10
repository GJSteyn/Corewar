/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 10:55:41 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/10 19:40:38 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_zjmp(struct s_process *bot)
{
	if (bot->carry)
		bot->next_pc = bot->current_pc + (bot->args[0] % IDX_MOD);
	f_printf("op: zjmp\n");
}
