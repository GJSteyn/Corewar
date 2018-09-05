/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strrchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 20:21:38 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/22 20:25:05 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*f_strrchr(char *str, char c)
{
	char *ret;

	ret = NULL;
	while (*str)
	{
		if (*str == c)
			ret = str;
		str++;
	}
	return (ret);
}
