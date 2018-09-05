/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_int2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:37:34 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/30 16:57:53 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pf_handle_int.h"

void	to_str(char *buf, t_tag *tag, va_list ap)
{
	long long			nbr;
	unsigned int		base;

	tag->mem_size = f_strchr("DOU", tag->spec) ? sizeof(long) : tag->mem_size;
	base = 10;
	if (f_toupper(tag->spec) == 'X' || tag->spec == 'p')
		base = 16;
	else if (f_toupper(tag->spec) == 'O')
		base = 8;
	else if (tag->spec == 'b')
		base = 2;
	if (f_strchr("uUxXoOp", tag->spec))
		nbr = get_size_mask(tag->mem_size, va_arg(ap, long long), false);
	else
	{
		nbr = get_size_mask(tag->mem_size, va_arg(ap, long long), true);
		if (nbr < 0)
		{
			nbr = -nbr;
			tag->is_neg = 1;
		}
	}
	tag->prefix = (nbr || f_toupper(tag->spec) == 'O') ? tag->prefix : false;
	pf_unbrtostr(nbr, buf, base);
}

char	*handle_width(t_tag *tag, char *buf)
{
	size_t	len;
	char	*ret;

	if ((buf[0] && (!tag->zeropad || tag->p_set)) || tag->spec == 'p')
		add_prefix(buf, tag);
	len = f_strlen(buf);
	tag->diff = tag->min_width - len;
	ret = f_strnew((MAX(tag->min_width, len)) + 2);
	if (tag->zeropad && !tag->left_just && !tag->p_set)
		f_memset(ret, '0', (MAX(tag->min_width, len)));
	else
		f_memset(ret, ' ', (MAX(tag->min_width, len)));
	if (tag->left_just)
		f_memcpy(ret, buf, len);
	else
		f_memcpy(ret + (MAX(tag->min_width, len)) - len, buf, len);
	if (tag->zeropad && !tag->p_set)
		add_prefix(ret, tag);
	return (ret);
}

char	*handle_precision(t_tag *tag, char *buf)
{
	size_t	len;
	char	*ret;

	if ((len = f_strlen(buf)) > tag->precision)
		tag->precision = len;
	ret = f_strnew(tag->precision + 2);
	f_memset(ret, '0', tag->precision);
	f_memcpy(ret + tag->precision - len, buf, len);
	return (ret);
}
