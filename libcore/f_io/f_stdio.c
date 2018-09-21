/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_stdio.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:08:20 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/21 10:41:21 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "f_io.h"
#include "s_file.h"
#include "f_memory.h"

static void	free_i(void)
{
	t_file	*stdi;

	stdi = f_stdio(0);
	f_closef(stdi);
}

static void	free_o(void)
{
	t_file	*stdo;

	stdo = f_stdio(1);
	f_closef(stdo);
}

static void	free_e(void)
{
	t_file	*stde;

	stde = f_stdio(2);
	f_closef(stde);
}

t_file		*f_stdio(int std_fd)
{
	static t_file	*stdi;
	static t_file	*stdo;
	static t_file	*stde;

	if (!stdi && std_fd == 0 && (stdi = (t_file*)f_memalloc(sizeof(*stdi))))
		(*stdi = (t_file)STDIN_).mode && (atexit(free_i));
	if (!stdo && std_fd == 1 && (stdo = (t_file*)f_memalloc(sizeof(*stdo))))
		(*stdo = (t_file)STDOUT_).mode && (atexit(free_o));
	if (!stde && std_fd == 2 && (stde = (t_file*)f_memalloc(sizeof(*stde))))
		(*stde = (t_file)STDERR_).mode && (atexit(free_e));
	if (std_fd == 0)
		return (stdi);
	if (std_fd == 1)
		return (stdo);
	if (std_fd == 2)
		return (stde);
	return (NULL);
}
