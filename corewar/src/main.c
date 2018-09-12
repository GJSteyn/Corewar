/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:09:15 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/12 12:05:13 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "list.h"
#include <stdio.h>

typedef struct s_process	t_process;

void				find_bot_info(t_vis *vis, int fd, int player_no)
{
	char	hold[PROG_NAME_LENGTH + COMMENT_LENGTH + 9];

	lseek(fd, AT_NAME, SEEK_SET);
	read(fd, hold, PROG_NAME_LENGTH);
	f_memcpy(vis->champs[player_no], hold, f_strlen(hold));
	f_bzero(hold, PROG_NAME_LENGTH + COMMENT_LENGTH + 9);
	lseek(fd, AT_COMMENT, SEEK_SET);
	read(fd, hold, COMMENT_LENGTH);
	f_memcpy(vis->desc[player_no], hold, f_strlen(hold));
}

struct s_process	*load_bot(t_vis	*vis ,char *path, int player_no)
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
	find_bot_info(vis, fd, player_no);
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

static int			count_bots(int argc, char **argv, int champ[])
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (++i < argc)
	{
		if (f_strstr(argv[i], ".cor"))
			champ[count++] = i;
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
	int		a;
	int		champ[4];

	vis = start_vis();
	player_no = 0;
	a = 0;
	if (argc < 2)
		return (0);
	g_env.player_total = count_bots(argc, argv, champ);
	process_list = list_create(free);
	// intro(vis);
	while (++player_no <= (int)g_env.player_total)
	{
		list_append(process_list, load_bot(argv[champ[a]], player_no));
		list_iterate(process_list, cycle);
		a++;
		f_printf("%d\n", a);
	}
	// while (corewar)
	// {
		visualizer(vis);
	// }
	end_vis(&vis);
}
