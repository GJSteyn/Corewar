/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:05:12 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/01 13:24:50 by wseegers         ###   ########.fr       */
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

static void		destroy_token(void *token)
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

static void		add_newline(t_list *list, char **str, size_t *line)
{
	t_token		*token;

	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = eol;
	token->line = *line;
	(*str)++;
	(*line)++;
	list_append(list, token);
}

static void		add_name(t_list *list, char **str, size_t line)
{
	t_token		*token;

	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = keyword;
	token->value.keyword = name;
	token->line = line;
	*str += f_strlen(NAME_CMD_STRING);
	list_append(list, token);
}

static void		add_comment(t_list *list, char **str, size_t line)
{
	t_token		*token;

	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = keyword;
	token->value.keyword = comment;
	token->line = line;
	*str += f_strlen(COMMENT_CMD_STRING);
	list_append(list, token);
}

static void		add_text(t_list *list, char **str, size_t line)
{
	t_token		*token;
	char		*tmp;

	token = (t_token*)f_memalloc(sizeof(t_token));
	tmp = *str;
	(*str)++;
	while (**str && **str != '"')
		(*str)++;
	token->type = text;
	token->line = line;
	token->value.text = f_strsub(tmp + 1, 0, *str - tmp - 1);
	(*str)++;
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
	while (f_strchr(LABEL_CHARS, **str))
		(*str)++;
	if (*str - tmp == 0)
	{
		write(2, "Label arg error\n", 17);			// Replace with better error or handle error differently
		exit(1);
	}
	token->value.text = f_strsub(tmp, 0, *str - tmp);
	token->line = line;
	(*str)++;
	list_append(list, token);
}

static void		add_label_def(t_list *list, char **str, size_t line)
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

static void		add_separator(t_list *list, char **str, size_t line)
{
	t_token		*token;

	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = separator;
	token->line = line;
	(*str)++;
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
	token->value.op = g_op_tab[op_type].bytecode;
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
		// write(1, "Newline\n", 8);
		add_newline(list, str, line);
	}
	else if (f_strmatch(*str, NAME_CMD_STRING))
	{
		// write(1, "Name\n", 5);
		add_name(list, str, *line);
	}
	else if (f_strmatch(*str, COMMENT_CMD_STRING))
	{
		// write(1, "Comment\n", 8);
		add_comment(list, str, *line);
	}
	else if (**str == '"')
	{
		// write(1, "String\n", 7);
		add_text(list, str, *line);
	}
	else if (f_isdigit(**str) || **str == '-')
	{
		// write(1, "Number\n", 7);
		add_number(list, str, *line);
	}
	else if (**str == DIRECT_CHAR)
	{
		// write(1, "Direct\n", 7);
		add_arg(list, str, *line);
	}
	else if (is_label(*str))
	{
		// write(1, "Label\n", 6);
		add_label_def(list, str, *line);
	}
	else if (**str == SEPARATOR_CHAR)
	{
		// write(1, "Separator\n", 10);
		add_separator(list, str, *line);
	}
	else if (is_op(*str))
	{
		// write(1, "Op\n", 3);
		add_op(list, str, *line);
	}
	else if (is_reg(*str))
	{
		// write(1, "Reg\n", 4);
		add_reg(list, str, *line);
	}
	else
	{
		printf("Lexical error on line: %zu\n", *line);
		exit(1);
	}
}

t_list			*lex(char *clean_line)
{
	t_list			*ret;
	size_t			line;

	ret = list_create(destroy_token);
	line = 0;
	while (*clean_line)
	{
		if (f_isspace(*clean_line) && *clean_line != '\n')		// Should f_isspace be checking for '\n'?
			clean_line++;
		else
			add_token(&clean_line, &line, ret);
	}
	return (ret);
}
