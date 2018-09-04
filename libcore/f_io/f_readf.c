/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_readf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 09:01:06 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/03 20:25:12 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "s_file.h"
#include "f_math.h"
#include "f_memory.h"
#include "f_print.h"

static int	check_buf(t_file *file)
{
	if (file->fpos == -1 || file->fpos == file->lread)
	{
		if (file->fpos > 0 && file->lread < file->cap)
		{
			file->fpos = -1;
			return (1);
		}
		else if (!f_feedf(file))
			return (1);
	}
	return (0);
}

ssize_t		f_readf(char *ptr, t_file *file, size_t n)
{
	size_t csize;
	size_t total;

	total = 0;
	if (!(file->mode == 'r' || file->mode == 'R' || file->mode == 'W'))
		return (-1);
	while (total < n)
	{
		if (check_buf(file))
			return (total);
		if (file->lread == -1)
			return (-1);
		csize = f_min(n - total, file->lread - file->fpos);
		f_memcpy(ptr, file->buf + file->fpos, csize);
		total += csize;
		ptr += csize;
		file->fpos += csize;
	}
	return (total);
}
