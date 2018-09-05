/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 22:48:45 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/04 23:40:22 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

struct s_process	*process_create(int pcode, unsigned int pc, bool carry)
{
	struct s_process	*bot;
	int					i;

	bot = (struct s_process*)malloc(sizeof(struct s_process));
	bot->process_code = -pcode;
	bot->pc = pc;
	bot->carry = carry;
	bot->delay = -1;
	bot->reg[0] = -pcode;
	i = 0;
	while (++i < REG_NUMBER)
		bot->reg[i] = 0;
	return (bot);
}
