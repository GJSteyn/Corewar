/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_file.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 06:47:34 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 18:12:49 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_FILE_H
# define S_FILE_H

# include <unistd.h>
# include <stddef.h>
# include "f_string.h"

# define F_BUFFSIZE (512)

typedef struct	s_file
{
	char		*path;
	char		mode;
	int			fd_in;
	int			fd_out;
	char		*buf;
	ssize_t		cap;
	ssize_t		fpos;
	ssize_t		lread;
}				t_file;

# define STDIN_ {NULL, 'r', 0, -2, f_strnew(F_BUFFSIZE), F_BUFFSIZE -1, -1, -2}
# define STDOUT_ {NULL, 'w', -2, 1, NULL, 0, -1, -2}
# define STDERR_ {NULL, 'w', -2, 2, NULL, 0, -1, -2}

# define STDIN f_stdio(0)
# define STDOUT f_stdio(1)
# define STDERR f_stdio(2)

ssize_t			f_feedf(t_file *file);
void			f_initf(t_file *file, char *path, char mode);
t_file			*f_stdio(int std_fd);

#endif
