/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_atol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 11:01:34 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/29 13:29:57 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int		errorcheck(char *nbr, int *error)
{
	int	i;

	i = 0;
	if (f_isdigit(nbr[i]) == 0)
	{
		*error = 1;
		return (1);
	}
	i++;
	return (0);
}

long	f_atol(char *nbr, int *error)
{
	long		ret;
	int			in;
	int			neg;

	ret = 0;
	in = 0;
	*error = 0;
	neg = 1;
	if (!(nbr))
		exit(write(2, "ATOL NULL ERROR\n", 16));
	while (f_isspace(nbr[in]))
		in++;
	if (nbr[in] == '-')
	{
		neg = -1;
		in++;
	}
	else if (nbr[in] == '+')
		in++;
	errorcheck(nbr + in, error);
	while (nbr[in] >= '0' && nbr[in] <= '9')
		ret = (ret * 10) + (nbr[in++] - '0');
	return (ret *= neg);
}
