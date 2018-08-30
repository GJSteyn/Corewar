/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:05:12 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/30 18:55:17 by gsteyn           ###   ########.fr       */
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

static int		f_intlen(int n)
{
	int		ret;

	ret = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

static char		*get_text(char *str)
{
	char			*tmp;
	char			*ret;

	tmp = str + 1;
	while (*tmp && *tmp != '"')
		tmp++;
	ret = f_strsub(str, 1, tmp - str - 2);
	return (ret);
}

static bool		is_label(char *str)
{
	while (f_strchr(LABEL_CHARS, *str))
		str++;
	if (*str == ':')
		return (true);
	return (false);
}

static void		add_newline(t_list *list, size_t line)
{
	struct s_token	*token;

	token = (struct s_token*)f_memalloc(sizeof(struct s_token));
	token->type = eol;
	token->line = line;
	list_append(list, token);
}

static void		add_name(t_list *list, size_t line)
{
	struct s_token	*token;

	token = (struct s_token*)f_memalloc(sizeof(struct s_token));
	token->type = keyword;
	token->value.keyword = name;
	token->line = line;
	list_append(list, token);
}

static void		add_comment(t_list *list)
{
	struct s_token	*token;

	token = (struct s_token*)f_memalloc(sizeof(struct s_token));
	token->type = keyword;
	token->value.keyword = comment;
	token->line = line;
	list_append(list, token);
}

static void		add_text(t_list *list, char **str, size_t line)
{
	struct s_token	*token;
	char			*string;

	token = (struct s_token*)f_memalloc(sizeof(struct s_token));
	string = get_text(str);
	*str += f_strlen(string) + 2;
	token->type = text;
	token->value.text = string;
	token->line = line;
	list_append(list, token);
}

static void		add_number(t_list *list, char **str, size_t line)
{
	struct s_token	*token;

	token = (struct s_token*)f_memalloc(sizeof(struct s_token));
	token->type = number;
	token->value.number = (int)f_atol(*str);
	token->line = line;
	*str += f_intlen(token->value.number);
	list_append(list, token);
}

static void		add_arg(t_list *list, char **str, size_t line)
{
	struct s_token	*token;

	token = (struct s_token*)f_memalloc(sizeof(struct s_token));
	token->type = arg;
	if (*str + 1 == ':')
	{
		token->value.arg = label;
		*str += 2;
	}
	else
	{
		token->value.arg = direct;
		*str += 1;
	}
	token->line = line;
	list_append(list, token);
}

static void		add_label(t_list *list, char **str, size_t line)
{
	struct s_token	*token;
	char			*tmp;
	char			*label;

	token = (struct s_token*)f_memalloc(sizeof(struct s_token));
	token->type = label;
	tmp = *str;
	while (*tmp != ':')
		tmp++;
	label = f_strsub(*str, 0, tmp - *str - 1);
	token->value.text = label;
	*str += tmp - *str + 1;
	token->line = line;
	list_append(list, token);
}

static void		add_token(char **str, size_t *line, t_list *list)
{
	if (**str == '\n')
	{
		add_newline(list, *line);
		(*line)++;
		(*str)++;
	}
	else if (f_strmatch(*str, NAME_CMD_STRING))
	{
		add_name(list, *line)
		*str += f_strlen(NAME_CMD_STRING);
	}
	else if (f_strmatch(*str, COMMENT_CMD_STRING))
	{
		add_comment(list, *line);
		*str += f_strlen(COMMENT_CMD_STRING);
	}
	else if (**str == '"')
		add_text(list, str, *line);				// Should str be incremented here?			(rather than in the function that gets called here)
	else if (f_isdigit(**str) || **str == '-')
		add_number(list, str, *line);			// Should str be incremented here?
	else if (**str == DIRECT_CHAR)
		add_arg(list, str, *line);				// Should str be incremented here?
	else if (is_label(*str))
		add_label(list, str, *line);			// Should str be incremented here?
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
		if (f_isspace(*it) && *it != '\n')		// Should f_isspace be checking for '\n'?
			it++;
		else
			add_token(&it, &line, ret);
	}
}
