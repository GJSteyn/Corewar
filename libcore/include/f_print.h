/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:41:29 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/24 21:35:05 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_PRINT_H
# define F_PRINT_H

# include <unistd.h>
# include <stdarg.h>
# include "f_io.h"

ssize_t		f_print_str_fd(int fd, const char *str);
ssize_t		f_print_str(const char *str);
ssize_t		f_print_err(const char *str);

void		f_print_nbr_fd(int fd, int nbr);
void		f_print_nbr(int nbr);

ssize_t		f_print_char_fd(int fd, char c);
ssize_t		f_print_char(char c);

int			f_vdprintf(int fd, const char *format, va_list ap);
int			f_vprintf(const char *format, va_list ap);
int			f_printf(const char *format, ...);
int			f_fprintf(t_file *file, const char *format, ...);
int			f_vfprintf(t_file *file, const char *format, va_list ap);

#endif
