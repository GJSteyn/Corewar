/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:05:57 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/18 15:25:33 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

typedef struct s_process	t_process;

#define INVALID_BOT(bot)		{f_printf("%s is not a valid bot\n", bot); exit(0);}

struct s_process	*load_bot(char *path, int player_no)
{
	unsigned int		i;
	int					fd;
	struct s_process	*bot;

	i = PLAYER_POS(player_no, g_env.player_total);
	if ((fd = open(path, O_RDONLY)) < 0)
		INVALID_BOT(path);
	f_printf("loading [0x%03x] %s\n", i, path);//debug
	lseek(fd, AT_CODE, SEEK_SET);
	read(fd, g_env.memory + i, CHAMP_MAX_SIZE);
	close(fd);
	bot = process_create(-player_no, i, false);
	get_next_op(bot);
	return (bot);
}
