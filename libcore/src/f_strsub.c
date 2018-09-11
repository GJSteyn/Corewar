/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strsub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:46:34 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/30 16:48:45 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

char	*f_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (s)
	{
		ret = f_strnew(len);
		if (!ret)
			return (NULL);
		while (i < len)
		{
			ret[i] = s[i + start];
			i++;
		}
		return (ret);
	}
	return (NULL);
}
