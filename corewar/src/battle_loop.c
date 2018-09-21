/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 08:01:06 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/21 11:46:39 by wseegers         ###   ########.fr       */
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
			if ((g_env.cycle_to_die =
				CYCLE_TO_DIE - (g_env.delta_count * CYCLE_DELTA)) < 0)
				break ;
		}
		list_iterate(process_list, run_cycle);
		g_env.cycle_to_die--;
		g_env.cycles++;
	}
}


static void	paint_champs(void)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
		set_vis_mem(i, g_env.memory[i], g_env.vis_env.owner[i]);
}

static bool	kill_check_vis(void *process)
{
	t_process	*bot;

	bot = (t_process*)process;
	if (bot->live)
	{
		bot->live = 0;
		return (false);
	}
	PAINT_MEM(GET_MEM(bot->current_pc), bot->current_pc);
	return (true);
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
		PAINT_MEM(GET_MEM(bot->current_pc), bot->current_pc);
		bot->current_pc = bot->next_pc;
		get_next_op(bot);
		PAINT_PC(GET_MEM(bot->current_pc), bot->current_pc);
	}
}

void	handle_key_press()
{
	int c;

	if ((c = getch()))
	{
		if (c == ' ')
			PAUSE;
		else if (c == 'q')
		{
			end_vis();
			exit(0);
		}
	}
}

void	battle_loop_vis(void)
{
	t_list	*process_list;

	process_list = g_env.process_list;
	paint_champs();

	while (process_list->size)
	{
		handle_key_press();
		if (g_env.pause)
			continue;
		if (g_env.cycle_to_die <= 0)
		{
			list_remove_if(process_list, kill_check_vis);
			if (g_env.live_counter > NBR_LIVE || g_env.last_delta == MAX_CHECKS)
			{
				g_env.delta_count++;
				g_env.last_delta = 1;
			}
			else
				g_env.last_delta++;
			g_env.live_counter = 0;
			if ((g_env.cycle_to_die = CYCLE_TO_DIE -
				(g_env.delta_count * CYCLE_DELTA)) < 0)
				break ;
		}
		list_iterate(process_list, run_cycle_vis);
		refresh();
		usleep(1000);
		g_env.cycle_to_die--;
		g_env.cycles++;
	}
}
