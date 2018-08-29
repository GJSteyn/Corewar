/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:05:12 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/29 19:19:41 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "core.h"
#include "op.h"
#include "s_token.h"
#include <stdbool.h>

static void		token_destroy(void *token)
{
	free(((struct s_token*)token)->value);
}

static bool		f_strmatch(const char *str, char *match)
{
	size_t			i;

	i = 0;
	if (!*str || !*match)
		return (false);
	while (match[i] && str[i])
	{
		if (match[i] != str[i])
			return (false);
		i++;
	}
	return (true);
}

static void		append_name(t_list *list)
{
	char		*data;

	data = f_strdup(NAME_CMD_STRING);
	list_append(list, data);
}

static void		append_comment(t_list *list)
{
	char		*data;

	data = f_strdup(COMMENT_CMD_STRING);
	list_append(list, data);
}

t_list			lex(char *clean_line)
{
	t_list			*ret;
	size_t			line;
	char			*it;

	ret = list_create(token_destroy);
	line = 0;
	it = line;
	while (*it)
	{
		if (f_strmatch(it, NAME_CMD_STRING))
			append_name(ret);
		else if (f_strmatch(it, COMMENT_CMD_STRING))
			append_comment(ret);
		else if (*it == '"')
			append_text(ret)
	}
}
