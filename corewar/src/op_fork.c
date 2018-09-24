/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:44:25 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/24 13:34:37 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_fork(struct s_process *bot)
{
	struct s_process	*new_bot;
	int					i;
	int					*old_reg;
	int					*new_reg;

	// print_op_basics(bot, "fork");
	// f_printf("----->@ %#.4x\n", WRAP_MEM(bot->current_pc + WRAP_IDX(bot->args[0])));
	g_env.vis_env.player_forks[-bot->created_by - 1]++;
	new_bot = process_create(bot->created_by,
		WRAP_MEM(bot->current_pc + WRAP_IDX(bot->args[0])),
		bot->carry);
	new_bot->live = bot->live;
	old_reg = bot->reg;
	new_reg = new_bot->reg;
	i = -1;
	while (++i < REG_NUMBER)
		new_reg[i] = old_reg[i];
	get_next_op(new_bot);
}
