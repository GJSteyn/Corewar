/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 23:38:55 by WSeegers          #+#    #+#             */
/*   Updated: 2018/08/28 14:18:09 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/f_string.h"

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
