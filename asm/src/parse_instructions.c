/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:57:41 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/04 22:39:04 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "label.h"

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

static void			add_arg(t_instr *instr, t_token_list *token_list, t_op operation)
{
	t_token			*token;

	token = DEQUE_TOKEN(token_list);
	if (token->type == number)
	{
		if (!operation.arg_type[i] & (t_arg_code)indirect)
		{
			f_putstr_err("Invalid Token indirect number");						// Better error handling please.
			exit(1);
		}
		instr->arg_type[i] = indirect;
		instr->arg_value = token->value.number;
	}
	else if (token->type == label_arg)
	{
		if (!operation.arg_type[i] & )
	}





	if (operation.arg_type[i] & )
		instr->arg_type[0] = reg;
	else if (token->type == )
}

static void			add_instruction(t_instr_list *instr_list, t_token_list *token_list)
{
	int					i;
	t_instruction		*instr;
	t_token				*token;
	t_op				operation;

	i = -1;
	instr = (t_instruction*)f_memalloc(sizeof(t_instruction));
	token = DEQUE_TOKEN(token_list);
	operation = g_op_tab[token->value.op - 1];
	instr->op = token->value.op;
	token_destroy(token);
	while (++i < operation.argc)
	{
		add_arg(instr, token_list, operation, i);
		token_validate((token = DEQUE_TOKEN(token_list)), separator, NULL);
	}
}

t_instr_list		*parse_instructions(t_token_list *token_list)
{
	size_t				offset;
	t_token				*token;
	t_instr_list		*instr_list;
	t_label_list		labels;
	t_label_list		dref_labels;

	offset = 0;
	instr_list = list_create(instruction_destroy);
	glabel_list(LABEL_LIST_INIT);
	gdref_list(LABEL_LIST_INIT);
	parse_eol(token_list);
	while (token_list)
	{
		if (PEEK_TOKEN(token_list)->type == label_def)
		{
			token = DEQUE_TOKEN(token_list);
			add_glabel(token->value.text, offset);
		}
		else if (PEEK_TOKEN(token_list)->type == op)
			add_instruction(intsr_list, token_list);
	}
}
