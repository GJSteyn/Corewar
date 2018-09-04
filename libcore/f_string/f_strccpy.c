/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strccpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:18:44 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/31 22:40:31 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_strccpy(char *dest, const char *src, char c)
{
	size_t i;

	i = -1;
	while (*src)
	{
		*dest++ = *src++;
		if (dest[-1] == c)
			return (dest);
	}
	return (NULL);
}
