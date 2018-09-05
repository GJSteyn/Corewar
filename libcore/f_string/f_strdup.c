/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 23:38:55 by WSeegers          #+#    #+#             */
/*   Updated: 2018/05/28 08:14:58 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_string.h"

char	*f_strdup(const char *s)
{
	int		len;
	char	*dup;

	len = 0;
	len = f_strlen(s);
	if (!(dup = f_strnew(len + 1)))
		return (NULL);
	dup[len] = '\0';
	while (--len >= 0)
	{
		dup[len] = s[len];
	}
	return (dup);
}
