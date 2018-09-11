/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_add_tokens2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:26:32 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/11 13:39:41 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"
#include "s_token.h"
#include "list.h"
#include "op.h"

void		add_label_arg(t_list *list, char **str, size_t line)
{
	t_token		*token;
	char		*tmp;

	(*str)++;
	tmp = *str;
	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = label_arg;
	while (f_strchr(LABEL_CHARS, **str))
		(*str)++;
	if (*str - tmp == 0)
		lex_error("Label arg error", line);
	token->value.text = f_strsub(tmp, 0, *str - tmp);
	token->line = line;
	list_append(list, token);
}

void		add_label_def(t_list *list, char **str, size_t line)
{
	t_token		*token;
	char		*tmp;

	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = label_def;
	tmp = *str;
	while (**str != ':')
		(*str)++;
	token->value.text = f_strsub(tmp, 0, *str - tmp);
	(*str)++;
	token->line = line;
	list_append(list, token);
}

void		add_direct(t_list *list, char **str, size_t line)
{
	t_token		*token;

	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = arg;
	token->line = line;
	token->value.arg = direct;
	*str += 1;
	list_append(list, token);
	if (**str == ':')
		add_label_arg(list, str, line);
	else if (f_isdigit(**str) || **str == '-')
		add_number(list, str, line);
	else
		lex_error("Lexical error {direct value}", line);
}

void		add_indirect(t_list *list, char **str, size_t line)
{
	t_token		*token;

	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = arg;
	token->line = line;
	token->value.arg = indirect;
	list_append(list, token);
	if (**str == ':')
		add_label_arg(list, str, line);
	else
		add_number(list, str, line);
}

void		add_separator(t_list *list, char **str, size_t line)
{
	t_token		*token;

	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = separator;
	token->line = line;
	(*str)++;
	list_append(list, token);
}
