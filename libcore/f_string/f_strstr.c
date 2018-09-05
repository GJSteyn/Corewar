/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:38:02 by WSeegers          #+#    #+#             */
/*   Updated: 2018/06/06 11:02:31 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_string.h"

char	*f_strstr(const char *haystack, const char *needle)
{
	size_t len_n;

	if (!*needle)
		return ((char*)haystack);
	len_n = f_strlen(needle);
	while (*haystack && f_strncmp(haystack, needle, len_n))
		haystack++;
	if (*haystack)
		return ((char*)haystack);
	return (NULL);
}
