/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_printf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:06:18 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/04 22:10:45 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_PRINTF_H
# define F_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include "f_print.h"
# include "s_printf_tag.h"
# include "f_string.h"
# include "f_memory.h"
# include "f_math.h"
# include <stdio.h>

# define PF_BUFFSIZE 512

typedef	struct	s_buffer
{
	int		fd;
	char	data[PF_BUFFSIZE];
	ssize_t	pos;
	size_t	total;
}				t_buffer;

void			flush(t_buffer *buf);
void			buffer_fmt(t_buffer *buf, const char **format);
void			buffer_arg(t_buffer *buf, char *s);
void			buffer_char(t_buffer *buf, char c);

int				pf_unbrtostr(unsigned long long unbr, char *str,
					unsigned int base);
int				pf_ftostr(long double nbr, char *str, unsigned int precision);
int				pf_wctostr(char *buf, int c);
bool			pf_handle_colour(t_buffer *buf, char **s);
char			*pf_handle_int(t_tag *tag, va_list ap);
char			*pf_wstrtostr(int *wstr, bool p_set, int precision);
char			*pf_handle_str(t_tag *tag, va_list ap);
void			pf_handle_char(t_tag *tag, va_list ap, t_buffer *buf);
const char		*get_width_prec(t_tag *tag, const char *format, va_list ap);

#endif
