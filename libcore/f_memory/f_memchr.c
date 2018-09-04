/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_memchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:19:54 by WSeegers          #+#    #+#             */
/*   Updated: 2018/05/27 17:09:36 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*f_memchr(const void *s, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*src;

	chr = (unsigned char)c;
	src = (unsigned char*)s;
	while (n--)
		if (*src == chr)
			return (src);
	return (NULL);
}
