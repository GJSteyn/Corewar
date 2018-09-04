/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_printf_tag.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 20:56:38 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/30 16:33:47 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PRINTF_TAG_H
# define S_PRINTF_TAG_H

# include <stdbool.h>
# include <stddef.h>
# include <stdarg.h>

# define SPECS "sSpdDioOuUxXcCeEfFgGaAn%b"
# define INT_SPEC "pdDioOuUxXb"
# define STR_SPEC "cCsS"
# define FLT_SPEC "eEfFgGaA"
# define OTH_SPEC "n%"

typedef struct	s_tag
{
	char		spec;

	bool		left_just;
	bool		sign;
	bool		space;
	bool		prefix;
	bool		zeropad;
	bool		sep;

	bool		mw_set;
	size_t		min_width;
	bool		va_width;
	int			diff;

	bool		p_set;
	size_t		precision;
	bool		va_prec;

	size_t		mem_size;
	bool		is_neg;
	const char	*format;
}				t_tag;

void			init_tag(t_tag *tag);
char			*get_tag(const char *format);
void			parse_tag(t_tag *tag, const char *format, va_list ap);
char			*get_tag(const char *format);
int				s_tag_get_prec(t_tag *tag, va_list ap);
int				s_tag_get_width(t_tag *tag, va_list ap);

#endif
