/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 22:48:45 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/18 15:10:49 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

struct s_process	*process_create(int pcode, unsigned int pc, bool carry)
{
	struct s_process	*bot;

	bot = (struct s_process*)malloc(sizeof(struct s_process));
	bot->id = g_env.next_id++;
	bot->created_by = pcode;
	bot->live = 0;
	bot->next_pc = pc;
	bot->current_pc = pc;
	bot->carry = carry;
	bot->delay = -1;
	bot->op = 0;
	f_bzero(bot->args, sizeof(bot->args));
	f_bzero(bot->reg, sizeof(bot->reg));
	f_bzero(bot->is_reg, sizeof(bot->is_reg));
	bot->reg[0] = pcode;
	list_insert(g_env.process_list, bot, 0);
	return (bot);
}
