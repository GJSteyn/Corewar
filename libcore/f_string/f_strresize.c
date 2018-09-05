/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strresize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 22:08:32 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/02 18:15:48 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "f_string.h"

char	*f_strresize(char **old, size_t n)
{
	char *new;

	new = f_strnew(n);
	f_strncpy(new, *old, n);
	f_strdel(old);
	*old = new;
	return (new);
}
