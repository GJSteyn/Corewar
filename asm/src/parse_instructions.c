/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:57:41 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/11 16:54:42 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "s_label.h"
#include "s_instruction.h"
#include "f_print.h"

typedef struct s_instruction	t_instruction;
typedef	enum e_type				t_type;
typedef union u_value			t_value;
typedef enum e_arg_code			t_arg_code;

static size_t		parse_eol(t_token_list *token_list)
{
	t_token *token;
	size_t	nr;

	nr = 0;
	while (PEEK_TOKEN(token_list)->type == (t_type)eol)
	{
		token = DEQUE_TOKEN(token_list);
		token_destroy(&token);
		nr++;
	}
	return (nr);
}

static int			add_arg(t_instruction *instr, t_token_list *token_list,
							t_op operation, int i)
{
	int				increment;
	t_token			*token;

	increment = 0;
	token = DEQUE_TOKEN(token_list);
	if (token->type != arg)
		parse_error("Arg parse error", token->line);
	if (!(operation.arg_type[i] & token->value.arg))
		parse_error("Arg not compatible with op", token->line);
	instr->arg_type[i] = token->value.arg;
	if (token->value.arg == direct)
		increment = DIR_SIZE - (operation.unknown2 << 1);
	else if (token->value.arg == indirect)
		increment = IND_SIZE;
	else if (token->value.arg == reg)
		increment = 1;
	token_destroy(&token);
	token = DEQUE_TOKEN(token_list);
	if (token->type == label_arg)
		add_gdref(f_strdup(token->value.text), &(instr->arg_value[i]),
		goffset(0));
	else if (token->type == number)
		instr->arg_value[i] = token->value.number;
	token_destroy(&token);
	return (increment);
}

static void			add_instruction(t_instr_list *instr_list, t_token *token,
									t_token_list *token_list)
{
	int					i;
	t_instruction		*instr;
	t_op				operation;
	int					increment;

	i = -1;
	increment = 1;
	instr = (t_instruction*)f_memalloc(sizeof(t_instruction));
	operation = g_op_tab[token->value.op - 1];
	instr->op = token->value.op;
	while (++i < operation.argc)
	{
		increment += add_arg(instr, token_list, operation, i);
		token = DEQUE_TOKEN(token_list);
		if (token->type == eol && i != operation.argc - 1)
			parse_error("Incorrect number of args", token->line);
		else if (token->type != separator && token->type != eol)
			parse_error("Separator error", token->line);
		token_destroy(&token);
	}
	list_append(instr_list, instr);
	goffset(increment + operation.has_encoding_byte);
}

t_instr_list		*parse_instructions(t_token_list *token_list,
												t_header *header)
{
	t_token				*token;
	t_instr_list		*instr_list;

	goffset(0);
	instr_list = list_create(instruction_destroy);
	glabel_list(LABEL_LIST_INIT);
	gdref_list(LABEL_LIST_INIT);
	parse_eol(token_list);
	while ((token = DEQUE_TOKEN(token_list)))
	{
		if (token->type == label_def)
			add_glabel(f_strdup(token->value.text), goffset(0));
		else if (token->type == op)
			add_instruction(instr_list, token, token_list);
		token_destroy(&token);
	}
	parse_set_labels();
	header->prog_size = (unsigned int)goffset(0);
	return (instr_list);
}
