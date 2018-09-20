/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 08:01:06 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/20 12:11:52 by wseegers         ###   ########.fr       */
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
	if (!bot->delay && bot->op)
		bot->op(bot);
	else
		bot->next_pc = (bot->next_pc + 1) % MEM_SIZE;
	bot->current_pc = bot->next_pc;
	get_next_op(bot);
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
	// f_printf("[%u]Kill @ %d\n", bot->id, bot->delay);
	return (true);
}

void	battle_loop(void)
{
	t_list	*process_list;

	process_list = g_env.process_list;
	while (process_list->size)
	{
		// f_printf("cycle no: %d | cycle_to_die %d\n", g_env.cycles, g_env.cycle_to_die);
		if (g_env.cycle_to_die <= 0)
		{
			list_remove_if(process_list, kill_check);
			if (g_env.live_counter > NBR_LIVE || g_env.last_delta == MAX_CHECKS)
			{
				g_env.delta_count++;
				g_env.last_delta = 1;
			}
			else
				g_env.last_delta++;
			g_env.live_counter = 0;
			// f_printf("last_delta -> %d\n", g_env.last_delta);
			if ((g_env.cycle_to_die = CYCLE_TO_DIE - (g_env.delta_count * CYCLE_DELTA)) < 0)
				break ;
		}
		list_iterate(process_list, run_cycle);
		g_env.cycle_to_die--;
		g_env.cycles++;
	}
}

static void	run_cycle_vis(void **process)
{
	t_process	*bot;

	bot = (t_process*)*process;
	bot->delay--;
	if (bot->delay <= 0)
	{
		if (!bot->delay && bot->op)
			bot->op(bot);
		else
			bot->next_pc = (bot->next_pc + 1) % MEM_SIZE;
		bot->current_pc = bot->next_pc;
		get_next_op(bot);
		set_vis_mem(bot->current_pc, g_env.memory[bot->current_pc] ,0);
	}
	return ;
}

void	battle_loop_vis(void)
{
	t_list	*process_list;

	process_list = g_env.process_list;
	while (process_list->size)
	{
		if (g_env.cycle_to_die <= 0)
		{
			list_remove_if(process_list, kill_check);
			if (g_env.live_counter > NBR_LIVE || g_env.last_delta == MAX_CHECKS)
			{
				g_env.delta_count++;
				g_env.last_delta = 1;
			}
			else
				g_env.last_delta++;
			g_env.live_counter = 0;
			if ((g_env.cycle_to_die = CYCLE_TO_DIE - (g_env.delta_count * CYCLE_DELTA)) < 0)
				break ;
		}
		list_iterate(process_list, run_cycle_vis);
		refresh();
		usleep(1000);
		g_env.cycle_to_die--;
		g_env.cycles++;
	}
}
