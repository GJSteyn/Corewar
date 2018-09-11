/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 06:25:52 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/11 10:52:14 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_live(struct s_process *bot)
{
	if (bot->args[0] == bot->process_code)
	{
		bot->live++;
		f_printf("op: live success\n");
	}
	else
		f_printf("op: live fail\n");
}
