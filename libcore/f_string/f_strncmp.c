/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:30:26 by WSeegers          #+#    #+#             */
/*   Updated: 2018/06/06 11:01:01 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		f_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (!n)
		return (0);
	i = 1;
	while (*s1 == *s2)
	{
		if (!*s1++ || i++ == n)
			return (0);
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
