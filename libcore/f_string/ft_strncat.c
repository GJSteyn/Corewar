/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:26:22 by WSeegers          #+#    #+#             */
/*   Updated: 2018/05/23 21:03:16 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*d;
	size_t	i;

	d = dest;
	i = 0;
	while (*d)
		d++;
	while (*src && i++ < n)
		*d++ = *src++;
	*d = '\0';
	return (dest);
}
