/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_dynamicstring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:26:27 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/29 17:38:30 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static char		*f_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*ret;

	if (s1 && s2)
	{
		len1 = f_strlen(s1);
		len2 = f_strlen(s2);
		i = 0;
		ret = f_memalloc(len1 + len2 + 1);
		if (!ret)
			return (NULL);
		while (len1--)
			ret[i++] = *s1++;
		while (len2--)
			ret[i++] = *s2++;
		ret[i] = '\0';
		return (ret);
	}
	return (NULL);
}

static void		*f_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (dest);
}

static char		*f_strdup(const char *s1)
{
	size_t	len;
	char	*dup;

	len = f_strlen(s1);
	dup = (char*)(f_memalloc(len + 1));
	if (!dup)
		return (NULL);
	f_memcpy(dup, s1, len);
	return (dup);
}

char			*f_dynamicstring(char **ori, char *add)
{
	char	*tmp;
	char	*ret;

	tmp = f_strdup(*ori);
	free(*ori);
	ret = f_strjoin(tmp, add);
	free(tmp);
	return (ret);
}
