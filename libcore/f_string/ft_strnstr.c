/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:23:48 by WSeegers          #+#    #+#             */
/*   Updated: 2018/05/24 16:05:44 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t len_n;
	size_t i;

	if (!*little)
		return ((char*)big);
	if (!len || (len_n = ft_strlen(little)) > ft_strlen(big) || len_n > len)
		return (NULL);
	i = 0;
	while (*big && ft_strncmp(big, little, len_n))
	{
		if (i++ >= len - len_n)
			return (NULL);
		big++;
	}
	return ((char*)big);
}
