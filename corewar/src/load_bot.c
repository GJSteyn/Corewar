/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:05:57 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/12 08:36:30 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

typedef struct s_process	t_process;

void 	get_next_op(t_process *bot); // debug

struct s_process	*load_bot(char *path, int player_no)
{
	unsigned int		i;
	int					fd;
	struct s_process	*bot;

	i = PLAYER_POS(player_no, g_env.player_total);
	if ((fd = open(path, O_RDONLY)) < 0)
	{
		exit(0);
		f_printf("%s not found\n", path);
	}
	lseek(fd, AT_CODE, SEEK_SET);
	read(fd, g_env.memory + i, CHAMP_MAX_SIZE);
	close(fd);
	bot = process_create(-player_no, i, false);
	get_next_op(bot);
	return (bot);
}
