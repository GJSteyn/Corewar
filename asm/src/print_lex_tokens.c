/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lex_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 12:06:35 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/14 12:07:17 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "f_print.h"
#include "s_instruction.h"
#include "list.h"

typedef struct s_instruction	t_instruction;

static void		print_value(t_token *t)
{
	if (t->type == keyword)
	{
		if (t->value.keyword == name)
			f_printf(" [%s]", NAME_CMD_STRING);
		else
			f_printf(" [%s]", COMMENT_CMD_STRING);
	}
	else if (t->type == text || t->type == label_def || t->type == label_arg)
		f_printf(" [%s]", t->value.text);
	else if (t->type == op)
		f_printf(" [%s]", g_ops[t->value.op]);
	else if (t->type == number)
		f_printf(" [%d]", t->value.number);
	else if (t->type == arg)
		f_printf(" [%s]", g_args[t->value.arg]);
	else
		f_printf(" [(null)]");
}

void			print_instructions(t_header *header, t_instr_list *instr_list)
{
	t_list_node		*instr;
	int				i;

	f_printf("HEADER\n	NAME: %7s\n	COMMENT: %7s\n",
										header->prog_name, header->comment);
	instr = instr_list->head;
	while (instr)
	{
		f_printf("OP: %s\n", g_ops[((t_instruction*)instr->data)->op]);
		i = -1;
		while (++i < g_op_tab[((t_instruction*)instr->data)->op - 1].argc)
			f_printf("	ARG: type = %-8s | value = %-7d\n",
					g_args[((t_instruction*)instr->data)->arg_type[i]], ((t_instruction*)instr->data)->arg_value[i]);
		instr = instr->next;
	}
}

void			print_tokens(t_token_list *token_list)
{
	t_list_node		*t;
	size_t			i;

	t = token_list->head;
	i = 0;
	while (t)
	{
		f_printf("%zu: %4zu -> %-10s|", ((t_token*)t->data)->line, i++, g_types[((t_token*)t->data)->type]);
		print_value((t_token*)t->data);
		f_printf("\n");
		t = t->next;
	}
}
