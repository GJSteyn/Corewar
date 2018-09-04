/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_atof.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 12:20:40 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/20 04:55:45 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_string.h>

static int	parse_scientific_notation(const char **str, int e)
{
	int			sign;
	int			i;
	int			c;
	const char	*s;

	s = *str;
	sign = 1;
	i = 0;
	c = *s++;
	if (c == '+')
		c = *s++;
	else if (c == '-' && (c = *s++))
		sign = -1;
	while (f_isdigit(c) && (i = i * 10 + (c - '0')))
		c = *s++;
	e += i * sign;
	*str = s;
	return (e);
}

double		f_atof(const char *s)
{
	double	a;
	int		e;
	int		c;
	int		sign;

	a = 0.0;
	e = 0;
	while (!f_isdigit(*s) && *s != '-')
		s++;
	sign = (*s && *s == '-' && s++) ? -1 : 1;
	while ((c = *s++) != '\0' && f_isdigit(c))
		a = a * 10.0 + (c - '0');
	if (c == '.')
		while ((c = *s++) != '\0' && f_isdigit(c))
		{
			a = a * 10.0 + (c - '0');
			e = e - 1;
		}
	if (c == 'e' || c == 'E')
		e = parse_scientific_notation(&s, e);
	while (e > 0 && (e--))
		a *= 10.0;
	while (e < 0 && (e++))
		a *= 0.1;
	return (a * sign);
}
