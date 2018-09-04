/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_int.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:39:30 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/30 16:57:25 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_HANDLE_INT_H
# define PF_HANDLE_INT_H

# include <stdarg.h>
# include <stdint.h>
# include "f_string.h"
# include "f_memory.h"
# include "s_printf_tag.h"
# include "f_printf.h"

void					to_str(char *buf, t_tag *tag, va_list ap);
char					*handle_width(t_tag *tag, char *buf);
char					*handle_precision(t_tag *tag, char *buf);
void					hextoupper(char *c);
unsigned long long		get_size_mask(size_t n, long long nbr,
																bool has_sign);
void					add_prefix(char *buf, t_tag *tag);

#endif
