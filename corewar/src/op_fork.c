/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:44:25 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/10 20:39:43 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "op_function.h"

void	op_fork(struct s_process *bot)
{
	struct s_process	*new_bot;
	int					i;
	int					*old_reg;
	int					*new_reg;

	new_bot = process_create(bot->process_code,
		WRAP_MEM(bot->current_pc + (bot->args[0] % IDX_MOD)),
		bot->carry);
	old_reg = bot->reg;
	new_reg = new_bot->reg;
	i = -1;
	while (++i < REG_NUMBER)
		new_reg[i] = old_reg[i];
	list_insert(g_env.process_list, new_bot, 0);
	f_printf("op: fork\n");
}
