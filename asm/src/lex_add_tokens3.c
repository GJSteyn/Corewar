/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_add_tokens3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:27:44 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/11 13:28:44 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"
#include "s_token.h"
#include "list.h"
#include "op.h"

void		add_op(t_list *list, char **str, size_t line)
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

void		add_reg(t_list *list, char **str, size_t line)
{
	t_token		*token;

	token = (t_token*)f_memalloc(sizeof(t_token));
	token->type = arg;
	token->value.arg = reg;
	token->line = line;
	(*str)++;
	list_append(list, token);
	add_number(list, str, line);
}

void		skip_line(char **str)
{
	while (**str != '\n')
		(*str)++;
}
