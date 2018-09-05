/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:57:41 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/05 04:53:33 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "s_label.h"
#include "s_instruction.h"

typedef struct s_instruction	t_instruction;
typedef	enum e_type				t_type;
typedef union u_value			t_value;
typedef enum e_arg_code			t_arg_code;

static size_t	parse_eol(t_token_list *token_list)
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

static int			add_arg(t_instruction *instr, t_token_list *token_list, t_op operation, int i, size_t *offset)
{
	t_token			*token;

	token = DEQUE_TOKEN(token_list);
	if (token->type != arg)
	{
		f_putstr_err("Arg parse error");						// Better error output please. Include line number as well.
		exit(1);
	}
	if (!(operation.arg_type[i] & token->value.arg))
	{
		f_putstr_err("Arg not compatible with op");				// Better error output please. Include line number as well.
		exit(1);
	}
	instr->arg_type[i] = token->value.arg;
	token_destroy(&token);
	token = DEQUE_TOKEN(token_list);
	if (token->type == label_arg)
		add_gdref(f_strdup(token->value.text), &(instr->arg_value[i]), *offset);
	else if (token->type == number)
		instr->arg_value[i] = token->value.number;
	if (token->value.arg == direct)
		return (4);
	else if (token->value.arg == indirect)
		return (2);
	else if (token->value.arg == reg)
		return (1);
	return (0);
}

static int			add_instruction(t_instr_list *instr_list, t_token *token, t_token_list *token_list, size_t *offset)
{
	int					i;
	size_t				offset_increment;
	t_instruction		*instr;
	t_op				operation;

	i = -1;
	offset_increment = 0;
	instr = (t_instruction*)f_memalloc(sizeof(t_instruction));
	operation = g_op_tab[token->value.op - 1];
	instr->op = token->value.op;
	while (++i < operation.argc)
	{
		offset_increment += add_arg(instr, token_list, operation, i, offset);
		token = DEQUE_TOKEN(token_list);
		if (token->type == eol && i != operation.argc - 1)
		{
			f_putstr_err("Incorrect number of args");			// Better error output please. Include line number as well.
			exit(1);
		}
		else if (token->type != separator)
		{
			f_putstr_err("Separator error");					// Better error output please. Include line number as well.
			exit(1);
		}
	}
	list_append(instr_list, instr);
	offset_increment += operation.has_encoding_byte;
	return (offset_increment);
}

t_instr_list		*parse_instructions(t_token_list *token_list)
{
	size_t				offset;
	t_token				*token;
	t_instr_list		*instr_list;
	// t_label_list		labels;
	// t_label_list		dref_labels;

	offset = 0;
	instr_list = list_create(instruction_destroy);
	glabel_list(LABEL_LIST_INIT);
	gdref_list(LABEL_LIST_INIT);
	parse_eol(token_list);
	while ((token = DEQUE_TOKEN(token_list)))
	{
		if (token->type == label_def)
			add_glabel(token->value.text, offset);
		else if (PEEK_TOKEN(token_list)->type == op)
			offset += add_instruction(instr_list, token, token_list, &offset);
		token_destroy(&token);
	}
	parse_set_labels();
	return (instr_list);										// The offset is essentially the program size at this point. Find a way to pass this to Phil.
}
