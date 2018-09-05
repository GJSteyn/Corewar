/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_memcmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:53:34 by WSeegers          #+#    #+#             */
/*   Updated: 2018/05/28 06:27:41 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		f_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*mem1;
	unsigned char	*mem2;

	if (!n)
		return (0);
	mem1 = (unsigned char*)s1;
	mem2 = (unsigned char*)s2;
	while (*mem1 == *mem2)
	{
		if (!--n)
			return (0);
		mem1++;
		mem2++;
	}
	return (*mem1 - *mem2);
}
