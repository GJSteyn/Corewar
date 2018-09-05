/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:31:02 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/30 15:31:30 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "f_string.h"

ssize_t	f_print_str_fd(int fd, const char *str)
{
	return (write(fd, str, f_strlen(str)));
}

ssize_t	f_print_str(const char *str)
{
	return (f_print_str_fd(1, str));
}

ssize_t	f_print_err(const char *str)
{
	return (f_print_str_fd(2, str));
}
