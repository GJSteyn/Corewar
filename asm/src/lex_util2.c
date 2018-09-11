/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:23:11 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/11 13:38:58 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"
#include "op.h"
#include "f_print.h"
#include <stdbool.h>

bool		is_label(char *str)
{
	if (*str == ':')
		return (false);
	while (f_strchr(LABEL_CHARS, *str))
		str++;
	if (*str == ':')
		return (true);
	return (false);
}

void		lex_error(char *err_str, size_t line)
{
	f_fprintf(STDERR, "%s: Line %zu\n", err_str, line);
	exit(1);
}
