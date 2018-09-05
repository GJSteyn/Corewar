/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_openf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 08:19:06 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/06 07:59:08 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_file.h"
#include "f_memory.h"

t_file	*f_openf(char *path, char mode)
{
	t_file *file;

	file = (t_file*)f_memalloc(sizeof(*file));
	f_initf(file, path, mode);
	if (file->fd_in == -1 || file->fd_out == -1)
		return (NULL);
	return (file);
}
