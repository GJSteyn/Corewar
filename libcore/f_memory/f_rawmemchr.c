/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_rawmemchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:01:37 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/27 17:08:56 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*f_rawmemchr(const void *s, int c)
{
	unsigned char	chr;
	unsigned char	*src;

	chr = (unsigned char)c;
	src = (unsigned char*)s;
	while (src)
		if (*src == chr)
			return (src);
	return (NULL);
}
