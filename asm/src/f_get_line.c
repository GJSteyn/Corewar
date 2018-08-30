/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_get_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:23:59 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/29 17:52:46 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

static char		*f_strnew(size_t size)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = (char*)f_memalloc(size + 1);
	if (!ret)
		return (NULL);
	while (i < size)
		ret[i++] = '\0';
	return (ret);
}

char			*f_get_line(char *path)
{
	int			fd;
	int			rcount;
	char		buff[512 + 1];
	char		*ret;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Invalid file path\n", 18);
		exit(1);
	}
	ret = f_strnew(1);
	while ((rcount = read(fd, buff, 512)))
	{
		buff[rcount] = '\0';
		ret = f_dynamicstring(&ret, buff);
		if (rcount < 512)
			break ;
	}
	close(fd);
	return (ret);
}