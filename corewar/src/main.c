/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:09:15 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/05 02:17:19 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#include <stdio.h>

typedef struct s_process	t_process;

struct s_process	*load_bot(char *path, int player_no)
{
	unsigned int		i;
	int					fd;

	i = PLAYER_POS(player_no, g_env.player_total);
	if ((fd = open(path, O_RDONLY)) < 0)
	{
		exit(0);
		f_printf("%s not found\n", path);
	}
	lseek(fd, AT_CODE, SEEK_SET); // needs to be replaced with name parsing code
	read(fd, g_env.memory + i, CHAMP_MAX_SIZE);
	close(fd);
	return (process_create(player_no, i, false));
}

void 	get_next_op(t_process *bot)
{
	int		current;
	int		arg_size[3];	

	current = g_env.memory[bot->pc];
	get_arg_size(current, arg_size);
	//to be completed
}

void	cycle(void **process)
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

int		main(int argc, char *argv[])
{
	t_list	*process_list;

	if (!(argc == 2))
		return (0);
	g_env.player_total = 1;
	process_list = list_create(free);
	list_append(process_list, load_bot(argv[1], 1));
	list_iterate(process_list, cycle);
	// for (int i = 0; i < MEM_SIZE; i++)
	// {
	// 	if (i % 64 == 0)
	// 		f_printf("\n");
	// 	if (g_env.memory[i] > 0)
	// 		f_printf("%.2hhx ", g_env.memory[i]);
	// 	else
	// 		f_printf("__ ");
	// }
}
