/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strlcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:56:45 by WSeegers          #+#    #+#             */
/*   Updated: 2018/05/30 09:51:22 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_string.h"

size_t	f_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t ret;

	i = f_strnlen(dest, size);
	ret = i + f_strlen(src);
	if (i == size)
		return (ret);
	while (*src && i < size)
		dest[i++] = *src++;
	if (i == size)
		i--;
	dest[i] = '\0';
	return (ret);
}
