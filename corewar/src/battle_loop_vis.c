/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle_loop_vis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:00:29 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/27 12:42:39 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

typedef struct s_process	t_process;

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
	if (bot->delay > 0)
		return ;
	if (bot->delay <= 0 && bot->op)
	{
		bot->op(bot);
		bot->op = NULL;
	}
	else
	{
		PAINT_MEM(GET_MEM(bot->current_pc), bot->current_pc);
		get_next_op(bot);
		bot->delay--;
		PAINT_PC(GET_MEM(bot->current_pc), bot->current_pc);
	}
}

static void	handle_key_press(void)
{
	int		c;

	if ((c = getch()))
	{
		if (c == ' ')
		{
			if (g_env.vis_env.sound_status == 1)
			{
				kill(g_env.vis_env.sound_pid, SIGSTOP);
				g_env.vis_env.sound_status = 0;
			}
			else
			{
				kill(g_env.vis_env.sound_pid, SIGCONT);
				g_env.vis_env.sound_status = 1;
			}
			PAUSE;
		}
		else if (c == 'q')
		{
			end_vis();
			exit(0);
		}
		else if (c == 's')
			g_env.vis_env.vis_delay += 1000;
		else if (c == 'f')
			g_env.vis_env.vis_delay -= 1000;
		if (g_env.vis_env.vis_delay < MIN_DELAY)
			g_env.vis_env.vis_delay = MIN_DELAY;
		else if (g_env.vis_env.vis_delay > MAX_DELAY)
			g_env.vis_env.vis_delay = MAX_DELAY;
	}
}

void		battle_loop_vis(void)
{
	t_list	*process_list;
	int		check_key;

	process_list = g_env.process_list;
	paint_champs();
	check_key = 5;
	while (process_list->size)
	{
		if (g_env.cycles == g_env.flag_args[FLAG_MEM_DUMP])
			PAUSE;
		CHECK_INPUT(INPUT_CHECK_DELAY);
		if (g_env.pause)
			continue;
		if (g_env.cycle_to_die <= 0 && kill_process(kill_check_vis))
			break ;
		list_iterate(process_list, run_cycle_vis);
		update_gui_data();
		update_player_data();
		refresh();
		g_env.cycle_to_die--;
		g_env.cycles++;
		usleep(g_env.vis_env.vis_delay);
	}
	while (getch() != 'q')
		printf_victor(g_env.last_live);
}
