/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strtol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 17:04:17 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/02 00:51:16 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "f_string.h"

static unsigned char	f_charmap(char c)
{
	char	chr;

	chr = f_toupper(c);
	if (chr >= '0' && chr <= '9')
		return (chr - '0');
	if (chr >= 'A' && chr <= 'Z')
		return (chr - 'A' + 10);
	return (127);
}

static int				f_getbase(const char **nptr, int base)
{
	const char	*ptr;

	ptr = *nptr;
	if ((base == 0 || base == 16) && *ptr == '0')
	{
		if (*(++ptr) == 'x' && (++(ptr)))
			base = 16;
		else if (*ptr == '0')
			base = 8;
		else
			base = 10;
		*nptr = ptr;
	}
	return (base);
}

long					f_strtol(const char *nptr, char **endptr, int base)
{
	int		neg;
	long	result;
	char	digit;

	if (base < 0 || base > 36)
		return (0);
	neg = 0;
	result = 0;
	while (f_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			neg = 1;
	base = f_getbase(&nptr, base);
	while ((digit = f_charmap(*nptr++)) < base)
		if ((result = (result * base) + digit) < 0)
		{
			if (endptr)
				*endptr = (char*)nptr;
			return (LONG_MAX + neg);
		}
	if (endptr)
		*endptr = (char*)nptr;
	return (result + (result * -2 * neg));
}
