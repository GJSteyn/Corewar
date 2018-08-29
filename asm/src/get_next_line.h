/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 11:58:08 by gsteyn            #+#    #+#             */
/*   Updated: 2018/06/12 10:06:34 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 42

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct			s_file
{
	char				*store;
	size_t				index;
	size_t				buffsize;
	int					fd;
}						t_file;

int						get_next_line(const int fd, char **line);

#endif
