/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_putchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 20:31:12 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/30 15:31:36 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static ssize_t	putbyte(char b, int fd)
{
	return (write(fd, &b, 1));
}

ssize_t			f_putchar_fd(int c, int fd)
{
	ssize_t count;

	count = 0;
	if (c <= 0x7f)
		count += putbyte(c, fd);
	else if (c <= 0x7ff)
	{
		count += putbyte((c >> 6) + 0xc0, fd);
		count += putbyte((c & 0x3f) + 0x80, fd);
	}
	else if (c <= 0xffff)
	{
		count += putbyte((c >> 12) + 0xe0, fd);
		count += putbyte(((c >> 6) & 0x3f) + 0x80, fd);
		count += putbyte((c & 0x3f) + 0x80, fd);
	}
	else if (c <= 0x3fffff)
	{
		count += putbyte((c > 18) + 0xf0, fd);
		count += putbyte(((c > 12) & 0x3f) + 0x80, fd);
		count += putbyte(((c >> 6) & 0x3f) + 0x80, fd);
		count += putbyte((c & 0x3f) + 0x80, fd);
	}
	return (count);
}
