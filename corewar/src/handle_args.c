/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 09:53:25 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/21 12:03:48 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	load_players(char *players[], int player_total)
{
	int	i;

	i = -1;
	while (++i < player_total)
		load_bot(players[i], i + 1);
}

static int	set_flag(int arg_no, char *argv[], int argc)
{
	long	flag_no;
	int		i;
	int		j;
	char	*arg;

	i = arg_no;
	arg = argv[arg_no];
	j = 0;
	while ( arg[++j] && (flag_no = GET_FLAG(arg[j])))
	{
		if (flag_no < 0)
			FATAL("Invalid  flag\n")
		SET_FLAG(flag_no);
		if (HAS_VAL(arg[j]))
		{
			if (++i >= argc)
				FATAL("Not enough arguments\n")
			if (!f_isdigits(argv[i]))
				FATAL("Flag must be followed by numbers\n")
			SET_FARG(flag_no, f_atoi(argv[i]));
		}
	}
	return (i);
}

void	handle_args(int argc, char *argv[])
{
	int		i;
	int		player_no;
	char	*arg;
	char	*players[MAX_PLAYERS];

	i = 0;
	player_no = 0;
	while (++i < argc)
	{
		arg = argv[i];
		if (arg[0] == '-' && arg[1])
			i = set_flag(i, argv, argc);
		else if (player_no > MAX_PLAYERS)
			FATAL("Too many players\n")
		else
			players[player_no++] = arg;
	}
	g_env.player_total = player_no;
	load_players(players, player_no);
}
