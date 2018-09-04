/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:00:50 by WSeegers          #+#    #+#             */
/*   Updated: 2018/06/01 14:32:21 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*f_strchr(const char *s, int c)
{
	char	chr;
	size_t	i;

	chr = (char)c;
	i = -1;
	while (s[++i] != chr)
		if (!s[i])
			return (NULL);
	return ((char*)(s + i));
}
