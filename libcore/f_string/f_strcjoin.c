/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strcjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 10:45:40 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/02 11:20:05 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_string.h"
#include "f_memory.h"

char	*f_strcjoin(char const *s1, char const *s2, char c)
{
	char	*ret;
	char	*cpy;

	ret = f_strnew(f_strlen(s1) + f_strlen(s2) + 1);
	cpy = f_memccpy(ret, s1, '\0', -1);
	cpy[-1] = c;
	f_strcpy(cpy, s2);
	return (ret);
}
