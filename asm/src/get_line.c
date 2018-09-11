/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:23:59 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/11 11:48:02 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*get_line(char *path)
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
