/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 04:31:12 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/30 16:18:02 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/f_printf.h"

static void	padding(int i, t_buffer *buf, bool zero)
{
	char c;

	if (zero)
		c = '0';
	else
		c = ' ';
	while (i)
	{
		buffer_char(buf, c);
		i--;
	}
}

void		pf_handle_char(t_tag *tag, va_list ap, t_buffer *buf)
{
	char	wchar[4];
	int		len;
	int		i;

	i = -1;
	if (tag->spec == 'C' || (tag->spec == 'c' && tag->mem_size >= sizeof(int)))
	{
		pf_wctostr(wchar, va_arg(ap, int));
		len = f_strlen(wchar);
		if (len < 1)
			len = 1;
	}
	else if (tag->spec == '%' && (len = 1))
		wchar[0] = '%';
	else if ((len = 1))
		wchar[0] = (char)va_arg(ap, int);
	if (tag->min_width > 1 && !tag->left_just)
		padding(tag->min_width - len, buf, tag->zeropad);
	while (++i < len)
		buffer_char(buf, wchar[i]);
	if (tag->min_width > 1 && tag->left_just)
		padding(tag->min_width - len, buf, false);
}
