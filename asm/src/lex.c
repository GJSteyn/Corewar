/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:05:12 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/31 17:28:28 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "core.h"
#include "op.h"
#include "s_token.h"
#include <stdbool.h>
#include <unistd.h>		// Remove
#include <stdio.h>		// Remove

typedef struct s_token		t_token;

static void		token_destroy(void *token)
{
	if (((t_token*)token)->type == text)
		free(((t_token*)token)->value.text);
}

static bool		f_strmatch(const char *str, char *match)
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

static bool		is_op(char *str)
{
	int				i;

	i = 16;
	while (--i >= 0)								// checking from the back because st and sti cause issues
	{
		if (f_strmatch((g_op_tab[i]).mnu, str))
			return (true);
	}
	return (false);
}

static bool		is_reg(char *str)
{
	if (*str == 'r' && f_isdigit(*(str + 1)))
		return (true);
	return (false);
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
	t_token		*token;

	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = eol;
	token->line = line;
	list_append(list, token);
}

static void		add_name(t_list *list, size_t line)
{
	t_token		*token;

	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = keyword;
	token->value.keyword = name;
	token->line = line;
	list_append(list, token);
}

static void		add_comment(t_list *list, size_t line)
{
	t_token		*token;

	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = keyword;
	token->value.keyword = comment;
	token->line = line;
	list_append(list, token);
}

static void		add_text(t_list *list, char **str, size_t line)
{
	t_token		*token;
	char		*tmp;

	token = (t_token*)f_memalloc(sizeof(t_token));
	tmp = *str + 1;
	while (*tmp && *tmp != '"')
		tmp++;
	token->type = text;
	token->line = line;
	token->value.text = f_strsub(*str + 1, 0, tmp - *str - 1);
	*str += f_strlen(token->value.text) + 2;
	list_append(list, token);
}

static void		add_number(t_list *list, char **str, size_t line)
{
	t_token		*token;
	int			error;							// because it's required by f_atol

	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = number;
	token->value.number = (int)f_atol(*str, &error);
	token->line = line;
	*str += f_intlen(token->value.number);
	list_append(list, token);
}

static void		add_label_arg(t_list *list, char **str, size_t line)
{
	t_token		*token;
	char		*tmp;

	tmp = *str;
	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = label_arg;
	while (f_strchr(LABEL_CHARS, *tmp))
		tmp++;
	if (tmp - *str == 0)
	{
		write(2, "Label arg error\n", 17);			// Replace with better error or handle error differently
		exit(1);
	}
	token->value.text = f_strsub(*str, 0, tmp - *str);
	token->line = line;
	*str += tmp - *str;
	list_append(list, token);
}

static void		add_label_def(t_list *list, char **str, size_t line)
{
	t_token		*token;
	char		*tmp;

	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = label_def;
	tmp = *str;
	while (*tmp != ':')
		tmp++;
	token->value.text = f_strsub(*str, 0, tmp - *str);
	*str += tmp - *str + 1;
	token->line = line;
	list_append(list, token);
}

static void		add_arg(t_list *list, char **str, size_t line)
{
	t_token		*token;

	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = arg;
	token->line = line;
	if (*(*str + 1) == ':')
	{
		token->value.arg = label;
		*str += 2;
		list_append(list, token);
		add_label_arg(list, str, line);
	}
	else
	{
		token->value.arg = direct;
		*str += 1;
		list_append(list, token);
	}
}

static void		add_separator(t_list *list, size_t line)
{
	t_token		*token;

	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = separator;
	token->line = line;
	list_append(list, token);
}

static void		add_op(t_list *list, char **str, size_t line)
{
	t_token		*token;
	int			op_type;

	op_type = 15;
	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = op;
	while (!f_strmatch(g_op_tab[op_type].mnu, *str))
		op_type--;
	token->value.op = op_type + 1;
	token->line = line;
	*str += f_strlen(g_op_tab[op_type].mnu);
	list_append(list, token);
}

static void		add_reg(t_list *list, char **str, size_t line)
{
	t_token		*token;

	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = arg;
	token->value.arg = reg;
	token->line = line;
	(*str)++;
	list_append(list, token);
}

static void		add_token(char **str, size_t *line, t_list *list)
{
	if (**str == '\n')
	{
		add_newline(list, *line);
		(*line)++;
		(*str)++;
		// write(1, "Newline\n", 8);
	}
	else if (f_strmatch(*str, NAME_CMD_STRING))
	{
		add_name(list, *line);
		*str += f_strlen(NAME_CMD_STRING);
		// write(1, "Name\n", 5);
	}
	else if (f_strmatch(*str, COMMENT_CMD_STRING))
	{
		add_comment(list, *line);
		*str += f_strlen(COMMENT_CMD_STRING);
		// write(1, "Comment\n", 8);
	}
	else if (**str == '"')
	{
		add_text(list, str, *line);				// Should str be incremented here?			(rather than in the function that gets called here)
		// write(1, "String\n", 7);
	}
	else if (f_isdigit(**str) || **str == '-')
	{
		add_number(list, str, *line);			// Should str be incremented here?
		// write(1, "Number\n", 7);
	}
	else if (**str == DIRECT_CHAR)
	{
		add_arg(list, str, *line);				// Should str be incremented here?
		// write(1, "Direct\n", 7);
	}
	else if (is_label(*str))
	{
		add_label_def(list, str, *line);			// Should str be incremented here?
		// write(1, "Label\n", 6);
	}
	else if (**str == SEPARATOR_CHAR)
	{
		add_separator(list, *line);
		(*str)++;
		// write(1, "Separator\n", 10);
	}
	else if (is_op(*str))
	{
		add_op(list, str, *line);
		// write(1, "Op\n", 3);
	}
	else if (is_reg(*str))
	{
		add_reg(list, str, *line);
		// write(1, "Reg\n", 4);
	}
	else
	{
		printf("Lexical error on line: %d\n", *line);
		exit(1);
	}
}

t_list			*lex(char *clean_line)
{
	t_list			*ret;
	size_t			line;
	char			*it;

	ret = list_create(token_destroy);
	line = 0;
	it = clean_line;
	while (*it)
	{
		if (f_isspace(*it) && *it != '\n')		// Should f_isspace be checking for '\n'?
			it++;
		else
			add_token(&it, &line, ret);
	}
	return (ret);
}
