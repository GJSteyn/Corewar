/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_sound.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:29:38 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/27 11:36:38 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		vm_sound(void)
{
	g_env.vis_env.sound_pid = fork();
	if (!g_env.vis_env.sound_pid)
	{
		execlp("afplay", "afplay", SOUND, NULL);
		exit(0);
	}
}
