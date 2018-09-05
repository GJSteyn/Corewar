/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_memrev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:53:16 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/07 20:01:26 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	f_memrev(void *mem, size_t size)
{
	size_t			i;
	unsigned char	temp;
	unsigned char	*m;

	i = -1;
	m = (unsigned char*)mem;
	while (--size > ++i)
	{
		temp = m[size];
		m[size] = m[i];
		m[i] = temp;
	}
}
