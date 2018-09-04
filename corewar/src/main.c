/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:09:15 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/04 21:52:33 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#include <stdio.h>

void	load_bot(char *path, int player_no)
{
	char			*mem;
	char			player[CHAMP_MAX_SIZE];
	unsigned int	i;
	int				fd;

	i = PLAYER_POS(player_no, g_env->player_total);
	mem = g_env->memory;
	if ((fd = open(*path)) < 0)
	{
		exit(0);
		printf("%s not found\n");
	}
	lseek(fd, AT_NAME, SEEK_SET);
	read(fd, player, CHAMP_MAX_SIZE);
}

int		main(argc, argv)
{
	
}
