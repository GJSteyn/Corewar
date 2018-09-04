/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:52:53 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/30 15:31:33 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "f_print.h"
#include "f_io.h"

int	f_vfprintf(t_file *file, const char *format, va_list ap)
{
	return (f_vdprintf(file->fd_out, format, ap));
}

int	f_vprintf(const char *format, va_list ap)
{
	return (f_vfprintf(STDOUT, format, ap));
}

int	f_printf(const char *format, ...)
{
	va_list ap;
	ssize_t	ret;

	va_start(ap, format);
	ret = f_vprintf(format, ap);
	va_end(ap);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	ssize_t	ret;

	va_start(ap, format);
	ret = f_vprintf(format, ap);
	va_end(ap);
	return (ret);
}
