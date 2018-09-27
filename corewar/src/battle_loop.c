/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 08:01:06 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/27 10:24:28 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

typedef struct s_process	t_process;

static void	run_cycle(void **process)
{
	t_process	*bot;

	bot = (t_process*)*process;
	bot->delay--;
	if (bot->delay > 0)
		return ;
	if (bot->delay <= 0 && bot->op)
	{
		bot->op(bot);
		bot->op = NULL;
	}
	else
	{
		get_next_op(bot);
		bot->delay--;
	}
}

static bool	kill_check(void *process)
{
	t_process	*bot;

	bot = (t_process*)process;
	if (bot->live)
	{
		bot->live = 0;
		return (false);
	}
	return (true);
}

void	battle_loop(void)
{
	t_list	*process_list;
	int		mem_dump;

	mem_dump = g_env.flag_args[FLAG_MEM_DUMP];
	process_list = g_env.process_list;
	while (process_list->size && g_env.cycles <= mem_dump)
	{
		if (g_env.cycle_to_die <= 0 && kill_process(kill_check))
			break ;
		list_iterate(process_list, run_cycle);
		g_env.cycle_to_die--;
		g_env.cycles++;
	}
	if(IS_FLAG_SET(FLAG_MEM_DUMP))
		print_memory();
}
