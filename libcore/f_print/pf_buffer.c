/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 10:16:59 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/30 12:36:57 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/f_printf.h"

void	flush(t_buffer *buf)
{
	buf->total += write(buf->fd, buf->data, buf->pos + 1);
	buf->pos = -1;
}

void	buffer_fmt(t_buffer *buf, const char **format)
{
	char *fmt;

	fmt = (char*)*format;
	while (*fmt && *fmt != '%')
	{
		if (buf->pos == PF_BUFFSIZE - 2)
		{
			flush(buf);
			f_bzero(&buf, sizeof(buf));
		}
		buf->data[++buf->pos] = *fmt++;
	}
	*format = fmt;
}

void	buffer_arg(t_buffer *buf, char *s)
{
	char *ptr;

	ptr = s;
	while (*s)
	{
		if (buf->pos == PF_BUFFSIZE - 2)
			flush(buf);
		buf->data[++buf->pos] = *s++;
	}
	f_strdel(&ptr);
}

void	buffer_char(t_buffer *buf, char c)
{
	if (buf->pos == PF_BUFFSIZE)
		flush(buf);
	buf->data[++buf->pos] = c;
}
