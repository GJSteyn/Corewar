/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 21:30:00 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/02 18:10:45 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_file.h"
#include "f_math.h"
#include "f_memory.h"
#include "f_print.h"

ssize_t	f_next_line(char **ptr, t_file *file)
{
	size_t csize;
	size_t total;

	if (!(file->mode == 'r' || file->mode == 'R' || file->mode == 'W'))
		return (-1);
	total = 0;
	*ptr = f_strnew(1);
	while (*(*ptr + total - 1) != '\n')
	{
		if (file->fpos == -1 || file->fpos == file->lread)
			if (!f_feedf(file))
				return (total);
		if (file->lread == -1)
			return (-1);
		csize = file->lread - file->fpos;
		f_strresize(ptr, csize + total);
		if (f_memccpy(*ptr + total, file->buf + file->fpos, '\n', csize))
			csize = f_strlen(*ptr + total);
		total += csize;
		file->fpos += csize;
	}
	if (*(*ptr + total - 1) == '\n')
		*(*ptr + total - 1) = '\0';
	return (total);
}
