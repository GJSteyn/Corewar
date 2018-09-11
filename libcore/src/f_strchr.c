/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 18:42:01 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/30 18:42:34 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

char	*f_strchr(const char *s, int c)
{
	size_t	s_len;
	size_t	i;

	s_len = f_strlen(s);
	i = 0;
	if (c == '\0')
		return ((char*)(s + s_len));
	while (i <= s_len)
	{
		if (s[i] == c)
			return ((char*)(s + i));
		i++;
	}
	return (NULL);
}
