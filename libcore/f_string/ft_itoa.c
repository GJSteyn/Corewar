/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 14:41:57 by WSeegers          #+#    #+#             */
/*   Updated: 2018/05/02 19:50:30 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nbr)
{
	int		size;
	t_uint	unbr;
	int		is_neg;
	char	*str;

	is_neg = 0;
	if (nbr < 0)
		is_neg = 1;
	size = ft_intlen(nbr) + is_neg;
	unbr = ft_abs(nbr);
	if (!(str = (char*)ft_memalloc(sizeof(*str) * (size + 1))))
		return (NULL);
	if (is_neg)
		str[0] = '-';
	str[--size] = (unbr % 10) + '0';
	while (--size >= is_neg)
		str[size] = ((unbr /= 10) % 10) + '0';
	return (str);
}
