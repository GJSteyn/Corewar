/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strsub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 21:54:41 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/02 15:31:21 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_string.h"

char	*f_strsub(char const *str, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	if (!str || !(ret = f_strnew(len)))
		return (NULL);
	i = -1;
	while (++i < len)
		ret[i] = str[start + i];
	return (ret);
}
