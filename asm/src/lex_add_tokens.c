/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_add_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:25:20 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/12 18:22:29 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"
#include "s_token.h"
#include "list.h"
#include "op.h"
#include <limits.h>

void		add_newline(t_list *list, char **str, size_t *line)
{
	t_token		*token;

	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = eol;
	token->line = *line;
	(*str)++;
	(*line)++;
	list_append(list, token);
}

void		add_name(t_list *list, char **str, size_t line)
{
	t_token		*token;

	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = keyword;
	token->value.keyword = name;
	token->line = line;
	*str += f_strlen(NAME_CMD_STRING);
	list_append(list, token);
}

void		add_comment(t_list *list, char **str, size_t line)
{
	t_token		*token;

	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = keyword;
	token->value.keyword = comment;
	token->line = line;
	*str += f_strlen(COMMENT_CMD_STRING);
	list_append(list, token);
}

void		add_text(t_list *list, char **str, size_t *line)
{
	t_token		*token;
	char		*tmp;

	token = (t_token*)f_memalloc(sizeof(t_token));
	tmp = *str;
	(*str)++;
	while (**str && **str != '"')
	{
		(*str)++;
		if (**str == '\n')
			(*line)++;
	}
	token->type = text;
	token->line = *line;
	token->value.text = f_strsub(tmp + 1, 0, *str - tmp - 1);
	(*str)++;
	list_append(list, token);
}

void		add_number(t_list *list, char **str, size_t line)
{
	t_token		*token;
	int			error;
	long		in;

	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = number;
	in = f_atol(*str, &error);
	if (in > INT_MAX)
		token->value.number = INT_MAX;
	else
		token->value.number = (int)in;
	token->line = line;
	while (f_isdigit(**str) || **str == '-')
		(*str)++;
	list_append(list, token);
}
