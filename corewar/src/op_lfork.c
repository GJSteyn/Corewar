/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:27:31 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/17 12:50:06 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void 	get_next_op(struct s_process *bot); // debug

void	op_lfork(struct s_process *bot)
{
	struct s_process	*new_bot;
	int					i;
	int					*old_reg;
	int					*new_reg;

	// print_op_basics(bot, "lfork");
	new_bot = process_create(bot->created_by,
		WRAP_MEM(bot->current_pc + bot->args[0]),
		bot->carry);
	new_bot->live = bot->live;
	old_reg = bot->reg;
	new_reg = new_bot->reg;
	i = -1;
	while (++i < REG_NUMBER)
		new_reg[i] = old_reg[i];
	get_next_op(bot);
}
