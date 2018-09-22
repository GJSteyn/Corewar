/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 20:25:29 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/22 13:30:59 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "corewar.h"

void	print_memory(void)
{
	for (int i = 0; i < MEM_SIZE; i++)
	{
	 	if (i % 64 == 0)
	 		f_printf("\n");
	 	if (g_env.memory[i])
	 		f_printf("%.2hhx ", g_env.memory[i]);
	 	else
	 		f_printf("__ ");
	}
}

void	print_bot(struct s_process *bot)
{
	int i;

	f_printf("ID:    %d\n", bot->id);
	f_printf("PCODE: %d\n", bot->created_by);
	f_printf("live:  %d\n", bot->live);
	f_printf("PC_cur:  %d\n", bot->current_pc);
	f_printf("PC_next: %d\n", bot->next_pc);
	f_printf("Carry: %d\n", bot->carry);
	i = -1;
	while (++i < REG_NUMBER)
		f_printf("R%.2d:   % 2d\n", i, bot->reg[i]);
	f_printf("Delay: %d\n", bot->delay);
	// i = -1;
	// while (++i < MAX_ARGS_NUMBER)
	// {
	// 	f_printf("Arg[%d]:   % d\n", i, bot->args[i]);
	// }
}

int		print_op_basics(struct s_process *bot, char *op)
{
	f_printf("[%4d] (%#.4x -> %#.4x) %s\n", bot->id, bot->current_pc, bot->next_pc, op);
	return(0);
}
