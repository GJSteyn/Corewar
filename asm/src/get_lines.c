/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:24:38 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/28 15:25:43 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "list.h"

t_list			*get_lines(char *path)
{
	int			fd;
	char		*in;
	t_list		*ret;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	ret = list_create(NULL);
	while (get_next_line(fd, &in))
	{
		list_append(ret, in);
		f_strdel(&in);
	}
	f_strdel(&in);
	close(fd);
	return (ret);
}
