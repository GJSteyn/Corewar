/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 21:38:59 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/23 20:59:26 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	t_uint	i;

	if (!s)
		return (NULL);
	if (!(ret = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = -1;
	while (s[++i])
		ret[i] = f(i, s[i]);
	return (ret);
}
