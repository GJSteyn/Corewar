/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_itoa_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 03:08:39 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/07 11:56:14 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "f_math.h"
#include "f_string.h"
#include "f_print.h"

char	*f_itoa_base(long long nbr, unsigned int base)
{
	int					neg;
	unsigned long long	unbr;
	int					i;
	char				buf[66];

	base = (base > 16) ? 16 : base;
	neg = (nbr < 0) ? 0 : 1;
	i = 66;
	unbr = f_abs(nbr);
	buf[--i] = "0123456789abcdef"[(unbr % base)];
	while (unbr)
		buf[--i] = "0123456789abcdef"[((unbr /= base) % base)];
	buf[i] = '-';
	return (f_strdup(buf + i + neg));
}

char	*f_utoa_base(unsigned long long unbr, unsigned int base)
{
	int					i;
	char				buf[66];

	base = (base > 16) ? 16 : base;
	i = 66;
	buf[--i] = "0123456789abcdef"[(unbr % base)];
	while (unbr)
		buf[--i] = "0123456789abcdef"[((unbr /= base) % base)];
	return (f_strdup(buf + i));
}
