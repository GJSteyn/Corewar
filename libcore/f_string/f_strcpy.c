/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 23:58:13 by WSeegers          #+#    #+#             */
/*   Updated: 2018/06/04 18:02:59 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_memory.h"
#include "f_string.h"

char	*f_strcpy(char *dest, const char *src)
{
	f_memccpy(dest, src, '\0', -1);
	return (dest);
}
