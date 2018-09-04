/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strtrim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:10:18 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/04 08:43:42 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_string.h"

char		*f_strtrim(char const *s)
{
	char	*ret;
	char	*p;
	char	c;

	ret = f_strnew(f_strlen(s));
	p = ret;
	while (f_isspace(*s))
		s++;
	while (*s)
	{
		if ((c = *s) == '\'' || c == '\"')
			while ((*p++ = *s++) && *s != c)
				;
		*p++ = *s++;
		if (f_isspace(*s))
		{
			*p++ = ' ';
			while (*s && f_isspace(*s))
				s++;
		}
	}
	return (ret);
}
