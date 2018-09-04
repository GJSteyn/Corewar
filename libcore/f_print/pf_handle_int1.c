/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_int1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 20:35:10 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/30 16:57:13 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pf_handle_int.h"

void				hextoupper(char *c)
{
	while (*c)
	{
		*c = f_toupper(*c);
		c++;
	}
}

unsigned long long	get_size_mask(size_t n, long long nbr,
																bool has_sign)
{
	if (has_sign)
	{
		if (n == 1)
			return ((char)nbr);
		if (n == 2)
			return ((short)nbr);
		if (!n || n == 4)
			return ((int)nbr);
		return ((long long)nbr);
	}
	if (n == 1)
		return ((unsigned char)nbr);
	if (n == 2)
		return ((unsigned short)nbr);
	if (!n || n == 4)
		return ((unsigned int)nbr);
	return ((unsigned long long)nbr);
}

static char			get_prefix(t_tag *tag)
{
	if (tag->is_neg)
		return ('-');
	else if (tag->sign)
		return ('+');
	else
		return (' ');
}

void				add_prefix(char *buf, t_tag *tag)
{
	int shift;

	shift = (tag->left_just) ? 0 : tag->diff;
	if ((f_strchr("xX", tag->spec) && tag->prefix) || tag->spec == 'p')
	{
		f_memmove(buf + 2 - (CLAMP(shift, 0, 2)), buf, f_strlen(buf) + 1);
		f_memcpy(buf, "0x", 2);
		(tag->left_just) && (buf[f_strlen(buf) - CLAMP(tag->diff, 0, 2)] = 0);
	}
	else if (f_toupper(tag->spec) == 'O' && tag->prefix && buf[0] != '0')
	{
		(tag->left_just) && (buf[f_strlen(buf) - CLAMP(tag->diff, 0, 1)] = 0);
		f_memmove(buf + 1 - (CLAMP(shift, 0, 1)), buf, f_strlen(buf) + 1);
		*buf = '0';
	}
	else if (f_strchr("dDi", tag->spec) && (tag->space || tag->sign
		|| tag->is_neg))
	{
		f_memmove(buf + 1 - (CLAMP(shift, 0, 1)), buf, f_strlen(buf) + 1);
		*buf = get_prefix(tag);
		(tag->left_just) && (buf[f_strlen(buf) - CLAMP(tag->diff, 0, 1)] = 0);
	}
}

char				*pf_handle_int(t_tag *tag, va_list ap)
{
	char	nbr_buf[64];
	char	*buf1;
	char	*buf2;

	to_str(nbr_buf, tag, ap);
	if (nbr_buf[0] == '0' && tag->p_set && !tag->precision &&
		!(f_toupper(tag->spec) == 'O' && tag->prefix))
		nbr_buf[0] = '\0';
	buf1 = handle_precision(tag, nbr_buf);
	buf2 = handle_width(tag, buf1);
	f_strdel(&buf1);
	if (tag->spec == 'X')
		hextoupper(buf2);
	return (buf2);
}
