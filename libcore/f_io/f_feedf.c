/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_feedf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 08:00:42 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/01 13:36:19 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_file.h"
#include "f_memory.h"
#include "f_string.h"

ssize_t	f_feedf(t_file *file)
{
	f_bzero(file->buf, file->cap);
	file->lread = read(file->fd_in, file->buf, file->cap);
	if (!file->lread)
		file->lread = f_strlen(file->buf);
	file->fpos = 0;
	return (file->lread);
}
