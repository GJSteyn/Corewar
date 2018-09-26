/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 09:53:25 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/26 16:36:39 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	load_players(char *players[],
	int player_total, int player_pos[MAX_PLAYERS])
{
	int		i;
	int		j;
	char	*sorted_players[MAX_PLAYERS];

	f_bzero(sorted_players, sizeof(sorted_players));
	i = -1;
	j = -1;
	while (++i < player_total)
	{
		if (player_pos[i] > 0 && player_pos[i] <= player_total)
			sorted_players[player_pos[i] - 1] = players[i];
		else
			players[++j] = players[i];
	}
	i = -1;
	j = -1;
	while (++i < player_total)
		if (!sorted_players[i])
			sorted_players[i] = players[++j];
	i = -1;
	while (++i < player_total)
		load_bot(sorted_players[i], i + 1);
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
	while (arg[++j] && (flag_no = GET_FLAG(arg[j])))
	{
		if (flag_no < 0)
			fatal("Invalid  flag\n");
		SET_FLAG(flag_no);
		if (HAS_VAL(arg[j]))
		{
			if (++i >= argc)
				fatal("Not enough arguments\n");
			if (!f_isdigits(argv[i]))
				fatal("Flag must be followed by numbers\n");
			SET_FARG(flag_no, f_atoi(argv[i]));
		}
	}
	return (i);
}

void		handle_args(int argc, char *argv[])
{
	int		i;
	int		player_no;
	char	*arg;
	char	*players[MAX_PLAYERS];
	int		player_pos[MAX_PLAYERS];

	i = 0;
	player_no = 0;
	while (++i < argc)
	{
		arg = argv[i];
		if (arg[0] == '-' && arg[1])
			i = set_flag(i, argv, argc);
		else if (player_no > MAX_PLAYERS)
			fatal("Too many players\n");
		else
		{
			player_pos[player_no] = g_env.flag_args[FLAG_PL_NO];
			players[player_no++] = arg;
			g_env.flag_args[FLAG_PL_NO] = 0;
		}
	}
	g_env.player_total = player_no;
	load_players(players, player_no, player_pos);
}
