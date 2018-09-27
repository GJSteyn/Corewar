/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:57:41 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/27 11:32:08 by wseegers         ###   ########.fr       */
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

static size_t	skip_eol(t_list_node **token)
{
	size_t	nr;

	nr = 0;
	while (((t_token*)(*token)->data)->type == eol)
	{
		*token = (*token)->next;
		nr++;
	}
	return (nr);
}

static int		add_arg(t_instruction *instr, t_list_node **token,
							t_op operation, int i)
{
	int				increment;

	increment = 0;
	*token = (*token)->next;
	if (((t_token*)(*token)->data)->type != arg)
		parse_error("Arg parse error", ((t_token*)(*token)->data)->line);
	if (!(operation.arg_type[i] & ((t_token*)(*token)->data)->value.arg))
		parse_error("Arg not compatible with op",
										((t_token*)(*token)->data)->line);
	instr->arg_type[i] = ((t_token*)(*token)->data)->value.arg;
	if (((t_token*)(*token)->data)->value.arg == direct)
		increment = DIR_SIZE - (operation.direct_index << 1);
	else if (((t_token*)(*token)->data)->value.arg == indirect)
		increment = IND_SIZE;
	else if (((t_token*)(*token)->data)->value.arg == reg)
		increment = 1;
	*token = (*token)->next;
	if (((t_token*)(*token)->data)->type == label_arg)
		add_gdref(f_strdup(((t_token*)(*token)->data)->value.text),
									&(instr->arg_value[i]), goffset(0));
	else if (((t_token*)(*token)->data)->type == number)
		instr->arg_value[i] = ((t_token*)(*token)->data)->value.number;
	return (increment);
}

static void		add_instruction(t_instr_list *instr_list, t_list_node **token)
{
	int					i;
	t_instruction		*instr;
	t_op				operation;
	int					increment;

	i = -1;
	increment = 1;
	instr = (t_instruction*)f_memalloc(sizeof(t_instruction));
	operation = g_op_tab[((t_token*)(*token)->data)->value.op - 1];
	instr->op = ((t_token*)(*token)->data)->value.op;
	while (++i < operation.argc)
	{
		increment += add_arg(instr, token, operation, i);
		*token = (*token)->next;
		if (((t_token*)(*token)->data)->type == eol && i != operation.argc - 1)
			parse_error("Incorrect number of args",
										((t_token*)(*token)->data)->line);
		else if (((t_token*)(*token)->data)->type != separator &&
										((t_token*)(*token)->data)->type != eol)
			parse_error("Separator error", ((t_token*)(*token)->data)->line);
	}
	list_append(instr_list, instr);
	goffset(increment + operation.has_encoding);
}

t_instr_list	*parse_instructions(t_token_list *token_list, t_header *header)
{
	t_list_node			*token;
	t_instr_list		*instr_list;

	goffset(0);
	instr_list = list_create(instruction_destroy);
	glabel_list(LABEL_LIST_INIT);
	gdref_list(LABEL_LIST_INIT);
	token = token_list->head;
	skip_eol(&token);
	while (token)
	{
		if (((t_token*)token->data)->type == label_def)
			add_glabel(f_strdup(((t_token*)token->data)->value.text),
															goffset(0));
		else if (((t_token*)token->data)->type == op)
			add_instruction(instr_list, &token);
		token = token->next;
	}
	parse_set_labels();
	header->prog_size = (unsigned int)goffset(0);
	return (instr_list);
}
