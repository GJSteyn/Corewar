/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strjoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:02:29 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/04 18:10:39 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_string.h"
#include "f_memory.h"

char	*f_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	ret = f_strnew(f_strlen(s1) + f_strlen(s2));
	f_memccpy(f_memccpy(ret, s1, '\0', -1) - 1, s2, '\0', -1);
	return (ret);
}
