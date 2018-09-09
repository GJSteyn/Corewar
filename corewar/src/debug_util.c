/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 20:25:29 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/09 20:26:31 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "corewar.h"

void	print_memory(void)
{
	for (int i = 0; i < MEM_SIZE; i++)
	{
	 	if (i % 64 == 0)
	 		f_printf("\n");
	 	if (g_env.memory[i] > 0)
	 		f_printf("%.2hhx ", g_env.memory[i]);
	 	else
	 		f_printf("__ ");
	}
}