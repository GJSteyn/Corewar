/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:19:08 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/11 13:38:34 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"
#include "op.h"
#include "e_type.h"
#include <stdbool.h>
#include <limits.h>

void		destroy_token(void *token)
{
	if (((t_token*)token)->type == text || ((t_token*)token)->type == label_arg
		|| ((t_token*)token)->type == label_def)
		free(((t_token*)token)->value.text);
}

bool		f_strmatch(const char *str, char *match)
{
	size_t			i;

	i = 0;
	if (!str || !match)
		return (false);
	while (match[i] && str[i])
	{
		if (match[i] != str[i])
			return (false);
		i++;
	}
	return (true);
}

int			f_intlen(long n)
{
	int		ret;

	ret = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		ret++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

bool		is_op(char *str)
{
	int				i;

	i = 16;
	while (--i >= 0)
	{
		if (f_strmatch((g_op_tab[i]).mnu, str))
			return (true);
	}
	return (false);
}

bool		is_reg(char *str)
{
	if (*str == 'r' && f_isdigit(*(str + 1)))
		return (true);
	return (false);
}
