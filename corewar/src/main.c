/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:09:15 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/13 17:42:40 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

typedef struct s_process	t_process;

void	run_cycle(void **process)
{
	t_process	*bot;

	bot = (t_process*)*process;
	bot->delay--;
	if (bot->delay > 0)
		return ;
	if (!bot->delay && bot->op)
		bot->op(bot);
	else
		bot->next_pc = (bot->next_pc + 1) % MEM_SIZE;
	bot->current_pc = bot->next_pc;
	get_next_op(bot);
}

bool	kill_check(void *process)
{
	t_process	*bot;

	bot = (t_process*)process;
	if (bot->live)
	{
		bot->live = 0;
		return (false);
	}
	f_printf("[%u]Kill @ %d\n", bot->id, bot->delay);
	return (true);
}

void	print_proc(void **process)
{
	t_process	*bot;

	bot = (t_process*)*process;
	f_printf("\n");
	print_bot(bot);
}

int		main(int argc, char *argv[])
{
	t_list	*process_list;

	if (!(argc == 2))
		return (0);

	// INNIT ENV
	f_bzero(g_env.memory, MEM_SIZE);
	g_env.player_total = 1;
	g_env.last_live = 0;
	g_env.next_id = 1;
	g_env.process_list = list_create(free);
	g_env.cycles = 1;
	g_env.live_counter = 0;
	g_env.cycle_to_die = CYCLE_TO_DIE;
	g_env.last_delta = 0;
	g_env.delta_count = 0;

	process_list = g_env.process_list;
	load_bot(argv[1], 1);
	// load_bot(argv[2], 2);

	// GAME LOOP
	// while (g_env.cycles != 5000 && process_list->size)
	while (process_list->size)
	{
		f_printf("cycle no: %d | cycle_to_die %d\n", g_env.cycles, g_env.cycle_to_die);
		list_iterate(process_list, run_cycle);
		if (g_env.cycle_to_die <= 1)
		{
			list_remove_if(process_list, kill_check);
			if (g_env.live_counter > NBR_LIVE || g_env.last_delta == MAX_CHECKS)
			{
				g_env.delta_count++;
				g_env.last_delta = 1;
			}
			else
				g_env.last_delta++;
			g_env.cycle_to_die = CYCLE_TO_DIE - g_env.delta_count * CYCLE_DELTA;
		}
		g_env.cycle_to_die--;
		g_env.cycles++;
	}

	// f_printf("\n");
	print_memory();
	f_printf("\n");
	// f_print_bot(list_get(process_list, 0));
	f_printf("bots-> %d\n", g_env.process_list->size);
	// list_iterate(g_env.process_list, print_proc);
	f_printf("last_live-> %d\n", g_env.last_live);
	f_printf("cycles: %d\n", g_env.cycles);
}
