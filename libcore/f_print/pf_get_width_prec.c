/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_width_prec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 16:19:19 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/30 16:25:04 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "include/s_printf_tag.h"
#include "f_string.h"
#include "f_memory.h"
#include "f_print.h"
#include "f_math.h"

static void	va_width_prec(t_tag *tag, const char **format, va_list ap)
{
	int	arg;

	if (((*format)[0] == '*') && (*format)++)
	{
		arg = va_arg(ap, int);
		if (arg < 0)
			tag->left_just = true;
		tag->min_width = f_abs(arg);
	}
	if (((*format)[0] == '.' && (*format)[1] == '*') && ((*format) += 2))
	{
		arg = va_arg(ap, int);
		if (arg < 0)
			return ;
		tag->p_set = true;
		tag->precision = f_abs(arg);
	}
}

const char	*get_width_prec(t_tag *tag, const char *format, va_list ap)
{
	va_width_prec(tag, &format, ap);
	if (f_isdigit(*format))
	{
		tag->min_width = f_atoi(format);
		while (f_isdigit(*format))
			format++;
		tag->mw_set = true;
	}
	va_width_prec(tag, &format, ap);
	if (*format == '.' && format++)
	{
		tag->p_set = true;
		if (f_isdigit(*format))
		{
			tag->precision = f_atoi(format);
			while (f_isdigit(*format))
				format++;
		}
		else
			tag->precision = 0;
	}
	return (format);
}
