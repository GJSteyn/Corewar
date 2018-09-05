/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_wstrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 09:38:18 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/30 16:56:32 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/f_printf.h"
#include "f_memory.h"
#include "f_string.h"
#include <stdio.h>

char	*pf_wstrtostr(int *wstr, bool p_set, int precision)
{
	char	bufc[4];
	char	*buf;
	char	*temp;
	ssize_t	clen;
	int		len;

	len = 512;
	buf = f_strnew(len);
	clen = 0;
	while (*wstr)
	{
		clen += pf_wctostr(bufc, *wstr++);
		if (p_set && clen > precision)
			return (buf);
		if (clen > len)
		{
			temp = buf;
			buf = f_strnew((len *= 2));
			f_strcpy(buf, temp);
			f_strdel(&temp);
		}
		f_strlcat(buf, bufc, len);
	}
	return (buf);
}
