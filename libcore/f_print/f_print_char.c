/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:21:07 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/30 15:31:24 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ssize_t		f_print_char_fd(int fd, char c)
{
	return (write(fd, &c, 1));
}

ssize_t		f_print_char(char c)
{
	return (write(1, &c, 1));
}
