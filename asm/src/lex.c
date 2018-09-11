/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:05:12 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/11 13:40:15 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "core.h"
#include "op.h"
#include "f_print.h"
#include "s_token.h"
#include "lex.h"

static void		add_token(char **str, size_t *line, t_list *list)
{
	if (**str == '\n')
		add_newline(list, str, line);
	else if (**str == DIRECT_CHAR)
		add_direct(list, str, *line);
	else if (is_label(*str))
		add_label_def(list, str, *line);
	else if (f_isdigit(**str) || **str == '-' || **str == LABEL_CHAR)
		add_indirect(list, str, *line);
	else if (**str == SEPARATOR_CHAR)
		add_separator(list, str, *line);
	else if (is_reg(*str))
		add_reg(list, str, *line);
	else if (is_op(*str))
		add_op(list, str, *line);
	else if (**str == '"')
		add_text(list, str, *line);
	else if (f_strmatch(*str, NAME_CMD_STRING))
		add_name(list, str, *line);
	else if (f_strmatch(*str, COMMENT_CMD_STRING))
		add_comment(list, str, *line);
	else if (**str == '#')
		skip_line(str);
	else
		lex_error("Lexical error", *line);
}

t_list			*lex(char *clean_line)
{
	t_list			*ret;
	size_t			line;

	ret = list_create(destroy_token);
	line = 1;
	while (*clean_line)
	{
		if (f_isspace_notnewl(*clean_line))
			clean_line++;
		else
			add_token(&clean_line, &line, ret);
	}
	return (ret);
}
