/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_memmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:47:45 by WSeegers          #+#    #+#             */
/*   Updated: 2018/05/27 17:21:09 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_memory.h"

void	*f_memmove(void *dest, const void *src, size_t n)
{
	char	buf[n];

	if (n)
	{
		f_memcpy(buf, src, n);
		f_memcpy(dest, buf, n);
	}
	return (dest);
}
