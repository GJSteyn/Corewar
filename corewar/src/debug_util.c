/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 20:25:29 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/27 10:25:24 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_memory(void)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (i % 32 == 0)
			f_printf("\n0x%.4x : ", i);
		if (g_env.memory[i] > 0)
			f_printf("%.2hhx ", g_env.memory[i]);
		else
			f_printf("-- ");
	}
	f_printf("\n");
}


int		fatal(char *str)
{
	f_printf("error: %s\n", str);
	exit(0);
}
