/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_writef.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:33:15 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/01 00:36:20 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "f_io.h"
#include "f_print.h"

ssize_t	f_writef(t_file *file, char *ptr, size_t n)
{
	if (file->fd_out > 0)
		return (write(file->fd_out, ptr, n));
	return (0);
}
