/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_io.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 09:35:54 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/25 11:09:48 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_IO_H
# define F_IO_H

# include <unistd.h>
# include <stddef.h>
# include "s_file.h"

t_file	*f_openf(char *path, char mode);
ssize_t	f_readf(char *ptr, t_file *file, size_t n);
ssize_t	f_writef(t_file *file, char *ptr, size_t n);
ssize_t	f_next_line(char **ptr, t_file *file);
void	f_skip_line(t_file *file);
void	f_closef(t_file *file);

#endif
