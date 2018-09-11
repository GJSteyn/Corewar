/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:09:15 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/11 13:09:33 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "list.h"
#include <stdio.h>

typedef struct s_process	t_process;

struct s_process	*load_bot(char *path, int player_no)
{
	unsigned int		i;
	int					fd;

	i = PLAYER_POS(player_no, g_env.player_total);
	if ((fd = open(path, O_RDONLY)) < 0)
	{
		f_printf("%s not found\n", path);
		exit(0);
	}
	lseek(fd, AT_CODE, SEEK_SET); // needs to be replaced with name parsing code
	read(fd, g_env.memory + i, CHAMP_MAX_SIZE);
	close(fd);
	return (process_create(player_no, i, false));
}

void				get_next_op(t_process *bot)
{
	int		current;
	int		arg_size[3];

	(void)arg_size;
	current = g_env.memory[bot->pc];
	
	// get_arg_size(current, arg_size);
	//  to be completed

}

void				cycle(void **process)
{
	t_process *bot;

	bot = (t_process*)*process;
	if (bot->delay > 0)
		;
	else if (!bot->delay)
		bot->op(bot);
	else
		get_next_op(bot);
	bot->delay--;
}

static int			count_bots(int argc, char **argv)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (++i < argc)
	{
		if (f_strstr(argv[i], ".cor"))
			count++;
	}
	if (count > 4)
	{
		f_fprintf(STDERR, "Invalid number of Champions\n");
		exit(0);
	}
	return (count);
}

int					main(int argc, char *argv[])
{
	t_list	*process_list;
	t_vis	*vis;
	int		player_no;

	vis = start_vis();
	player_no = 0;
	if (argc < 2)
		return (0);
	g_env.player_total = count_bots(argc, argv);
	process_list = list_create(free);
	// visualizer(vis);
	intro(vis);
	while (++player_no <= (int)g_env.player_total)
	{
		list_append(process_list, load_bot(argv[1], player_no));
		list_iterate(process_list, cycle);
	}
	// while (corewar)
	{
		visualizer(vis);
	}
	end_vis(&vis);
}
