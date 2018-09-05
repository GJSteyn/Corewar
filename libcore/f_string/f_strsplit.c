/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 23:21:52 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/11 12:12:55 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_string.h"
#include "f_memory.h"

static size_t	count_splits(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		while (*s == c)
			s++;
		i++;
	}
	return (i);
}

static size_t	split_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s == c)
		s++;
	while (*s && *s++ != c)
		len++;
	return (len);
}

char			**f_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	**splits;

	if (!s)
		return (NULL);
	i = 0;
	if (!(splits = (char**)f_memalloc(sizeof(splits) *
												(count_splits(s, c) + 1))))
		return (NULL);
	while (*s == c)
		s++;
	while (*s)
	{
		len = split_len(s, c);
		if (!(splits[i] = f_strnew(len)))
			return (NULL);
		f_strncpy(splits[i++], s, len);
		while (*s && *s != c)
			s++;
		while (*s == c)
			s++;
	}
	return (splits);
}
