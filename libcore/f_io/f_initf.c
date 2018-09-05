/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_initf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 08:36:14 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/31 16:21:26 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "s_file.h"
#include "f_string.h"

void	f_initf(t_file *file, char *path, char mode)
{
	file->path = f_strdup(path);
	file->mode = mode;
	if (mode == 'r' || mode == 'R' || mode == 'W')
	{
		file->fd_in = open(path, O_RDONLY);
		file->buf = f_strnew(F_BUFFSIZE);
		file->cap = F_BUFFSIZE - 1;
	}
	else
		file->fd_in = -2;
	if (mode == 'R')
		file->fd_out = open(path, O_WRONLY, 0666);
	else if (mode == 'w')
		file->fd_out = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (mode == 'W' || mode == 'A')
		file->fd_out = open(path, O_WRONLY | O_CREAT | O_APPEND, 0666);
	else if (mode == 'a')
		file->fd_out = open(path, O_WRONLY | O_APPEND, 0666);
	else
		file->fd_out = -2;
	file->fpos = -1;
	file->lread = -2;
}
