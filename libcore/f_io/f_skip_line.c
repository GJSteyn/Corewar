/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_skip_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 01:21:38 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/02 01:26:01 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_io.h"
#include "f_string.h"

void	f_skip_line(t_file *file)
{
	char *delme;

	f_next_line(&delme, file);
	f_strdel(&delme);
}
