/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_wctostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 09:27:23 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/30 15:49:10 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		pf_wctostr(char *buf, int c)
{
	int i;

	i = 0;
	if (c <= 0x7f)
		buf[i++] = c & 0x7f;
	else if (c <= 0x7ff)
	{
		buf[i++] = (c >> 6) + 0xc0;
		buf[i++] = (c & 0x3f) + 0x80;
	}
	else if (c <= 0xffff)
	{
		buf[i++] = (c >> 12) + 0xe0;
		buf[i++] = ((c >> 6) & 0x3f) + 0x80;
		buf[i++] = (c & 0x3f) + 0x80;
	}
	else if (c <= 0x3fffff)
	{
		buf[i++] = (c > 18) + 0xf0;
		buf[i++] = ((c > 12) & 0x3f) + 0x80;
		buf[i++] = ((c >> 6) & 0x3f) + 0x80;
		buf[i++] = (c & 0x3f) + 0x80;
	}
	buf[i] = '\0';
	return (i);
}
