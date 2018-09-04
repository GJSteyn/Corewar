/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_tag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 22:37:56 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/30 16:23:18 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "include/s_printf_tag.h"
#include "include/f_printf.h"
#include "f_string.h"
#include "f_memory.h"
#include "f_print.h"
#include "f_math.h"

static const char	*get_flags(t_tag *tag, const char *format)
{
	bool is_flag;

	is_flag = true;
	while (is_flag)
	{
		is_flag = false;
		if ((is_flag = (*format == '-')))
			tag->left_just = true;
		else if ((is_flag = (*format == '+')))
			tag->sign = true;
		else if ((is_flag = (*format == ' ')))
			tag->space = true;
		else if ((is_flag = (*format == '#')))
			tag->prefix = true;
		else if ((is_flag = (*format == '0')))
			tag->zeropad = true;
		else if ((is_flag = (*format == '\'')))
			tag->sep = true;
		format += is_flag;
	}
	return (format);
}

static const char	*get_mem_size(t_tag *tag, const char *format)
{
	if (*format == 'h' && format++)
	{
		if (*format == 'h' && format++)
			tag->mem_size = sizeof(char);
		else
			tag->mem_size = sizeof(short);
	}
	else if (*format == 'l' && format++)
	{
		if (*format == 'l' && format++)
			tag->mem_size = sizeof(long long);
		else
			tag->mem_size = sizeof(long);
	}
	else if (*format == 'j' && format++)
		tag->mem_size = sizeof(intmax_t);
	else if (*format == 'z' && format++)
		tag->mem_size = sizeof(ssize_t);
	return (format);
}

static const char	*get_spec(t_tag *tag, const char *format)
{
	if (f_strchr(SPECS, format[0]))
		tag->spec = *format++;
	else
		return (format);
	if (tag->spec == 'p')
		tag->mem_size = sizeof(long long);
	return (format);
}

void				parse_tag(t_tag *tag, const char *format, va_list ap)
{
	init_tag(tag);
	format = get_flags(tag, format + 1);
	format = get_width_prec(tag, format, ap);
	format = get_mem_size(tag, format);
	if (*format)
	{
		format = get_spec(tag, format);
	}
	tag->format = format;
}
