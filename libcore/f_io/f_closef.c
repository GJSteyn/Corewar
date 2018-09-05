/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_closef.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:01:34 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/25 11:09:26 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "f_io.h"
#include "f_string.h"

void	f_closef(t_file *file)
{
	if (!file)
		return ;
	if (file->fd_in > 2)
	{
		close(file->fd_in);
		file->fd_in = -1;
	}
	if (file->fd_out > 2)
	{
		close(file->fd_out);
		file->fd_out = -1;
	}
	f_strdel(&file->buf);
	f_strdel(&file->path);
}
