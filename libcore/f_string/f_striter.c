/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 21:21:06 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/10 11:18:34 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	f_striter(char *s, void (*f)(char *))
{
	if (s && f)
		while (*s)
			f(s++);
}
