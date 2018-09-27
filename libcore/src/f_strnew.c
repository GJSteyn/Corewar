/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:49:09 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/30 16:49:22 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

char	*f_strnew(size_t size)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = f_memalloc(size + 1);
	if (!ret)
		return (NULL);
	while (i < size)
	{
		ret[i++] = '\0';
	}
	return (ret);
}
