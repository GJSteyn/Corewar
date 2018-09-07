/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.wethinkcode.co.z    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:57:41 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/07 11:01:18 by gsteyn           ###   ########.fr       */
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

static void			parse_error(char *err_str, size_t line)
{
	f_fprintf(STDERR, "%s: Line %zu\n", err_str, line);
	exit(1);
}

static int			add_arg(t_instruction *instr, t_token_list *token_list, t_op operation, int i, size_t *offset)
{
	int				ret;
	t_token			*token;

	ret = 0;
	token = DEQUE_TOKEN(token_list);
	if (token->type != arg)
		parse_error("Arg parse error", token->line);
	if (!(operation.arg_type[i] & token->value.arg))
		parse_error("Arg not compatible with op", token->line);
	instr->arg_type[i] = token->value.arg;
	if (token->value.arg == direct)
		ret = DIR_SIZE - (operation.unknown2 << 1);
	else if (token->value.arg == indirect)
		ret = IND_SIZE;
	else if (token->value.arg == reg)
		ret = 1;
	token_destroy(&token);
	token = DEQUE_TOKEN(token_list);
	if (token->type == label_arg)
		add_gdref(f_strdup(token->value.text), &(instr->arg_value[i]), *offset);
	else if (token->type == number)
		instr->arg_value[i] = token->value.number;
	token_destroy(&token);
	return (ret);
}

static int			add_instruction(t_instr_list *instr_list, t_token *token, t_token_list *token_list, size_t *offset)
{
	int					i;
	size_t				offset_increment;
	t_instruction		*instr;
	t_op				operation;

	i = -1;
	offset_increment = 1;
	instr = (t_instruction*)f_memalloc(sizeof(t_instruction));
	operation = g_op_tab[token->value.op - 1];
	instr->op = token->value.op;
	while (++i < operation.argc)
	{
		offset_increment += add_arg(instr, token_list, operation, i, offset);
		token = DEQUE_TOKEN(token_list);
		if (token->type == eol && i != operation.argc - 1)
			parse_error("Incorrect number of args", token->line);
		else if (token->type != separator && token->type != eol)
			parse_error("Separator error", token->line);
		token_destroy(&token);
	}
	list_append(instr_list, instr);
	offset_increment += operation.has_encoding_byte;
	return (offset_increment);
}

t_instr_list		*parse_instructions(t_token_list *token_list, t_header *header)
{
	size_t				offset;
	t_token				*token;
	t_instr_list		*instr_list;

	offset = 0;
	instr_list = list_create(instruction_destroy);
	glabel_list(LABEL_LIST_INIT);
	gdref_list(LABEL_LIST_INIT);
	parse_eol(token_list);
	while ((token = DEQUE_TOKEN(token_list)))
	{
		if (token->type == label_def)
			add_glabel(f_strdup(token->value.text), offset);
		else if (token->type == op)
			offset += add_instruction(instr_list, token, token_list, &offset);
		token_destroy(&token);
	}
	parse_set_labels();
	header->prog_size = (unsigned int)offset;
	return (instr_list);
}
