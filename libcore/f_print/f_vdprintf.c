/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_vdprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:23:17 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/30 16:56:50 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "include/f_printf.h"
#include "f_print.h"

static void	handle_tag(const char **format, va_list ap, t_buffer *buf)
{
	t_tag	tag;

	parse_tag(&tag, *format, ap);
	*format = tag.format;
	if (!tag.spec)
		return ;
	if (f_strchr(INT_SPEC, tag.spec))
		buffer_arg(buf, pf_handle_int(&tag, ap));
	else if (f_strchr("sS", tag.spec))
		buffer_arg(buf, pf_handle_str(&tag, ap));
	else if (f_strchr("cC%", tag.spec))
		pf_handle_char(&tag, ap, buf);
	return ;
}

int			f_vdprintf(int fd, const char *format, va_list ap)
{
	t_buffer	buf;

	f_bzero(&buf, sizeof(buf));
	buf.fd = fd;
	buf.pos = -1;
	buf.total = 0;
	while (*format)
	{
		buffer_fmt(&buf, &format);
		if (*format)
			handle_tag(&format, ap, &buf);
	}
	flush(&buf);
	return (buf.total);
}
