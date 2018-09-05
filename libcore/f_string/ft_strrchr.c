/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:13:09 by WSeegers          #+#    #+#             */
/*   Updated: 2018/05/23 11:09:38 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	chr;

	i = ft_strlen(s);
	chr = (char)c;
	while (s[i] != chr)
		if (i-- == 0)
			return (NULL);
	return ((char*)(s + i));
}
