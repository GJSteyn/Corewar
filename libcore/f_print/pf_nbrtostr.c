/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_nbrtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:39:54 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/30 15:28:46 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_memory.h"
#include "f_string.h"
#include "include/s_printf_tag.h"

int	pf_unbrtostr(unsigned long long unbr, char *str, unsigned int base)
{
	unsigned int		i;

	if (!unbr)
	{
		f_strcpy(str, "0");
		return (1);
	}
	i = -1;
	while (unbr)
	{
		str[++i] = "0123456789abcdef"[(unbr % base)];
		unbr /= base;
	}
	f_memrev(str, ++i);
	str[i] = '\0';
	return (i);
}
