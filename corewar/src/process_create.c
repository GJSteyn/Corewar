/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 22:48:45 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/11 10:58:25 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

// void 	get_next_op(struct s_process *bot);

struct s_process	*process_create(int pcode, unsigned int pc, bool carry)
{
	struct s_process	*bot;
	int					i;

	bot = (struct s_process*)malloc(sizeof(struct s_process));
	bot->process_code = pcode;
	bot->live = 0;
	bot->next_pc = pc;
	bot->current_pc = pc;
	bot->carry = carry;
	bot->delay = -1;
	i = -1;
	while (++i < REG_NUMBER)
		bot->reg[i] = 0;
	bot->reg[1] = pcode;
	// get_next_op(bot);
	return (bot);
}
