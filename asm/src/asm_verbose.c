/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_verbose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:15:52 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/13 20:38:09 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "f_print.h"
#include "s_instruction.h"
#include "list.h"

typedef struct s_instruction	t_instruction;
char		*g_types[9] =
{
	"keyword",
	"text",
	"label_def",
	"op",
	"arg",
	"label_arg",
	"number",
	"eol",
	"separator"
};

char		*g_ops[17] =
{
	"blank",
	"live",
	"ld",
	"st",
	"add",
	"sub",
	"and",
	"or",
	"xor",
	"zjmp",
	"ldi",
	"sti",
	"fork",
	"lld",
	"lldi",
	"lfork",
	"aff"
};

char		*g_args[5] =
{
	"blank",
	"reg",
	"direct",
	"label",
	"indirect"
};

char		g_argchar[5] =
{
	' ',
	'r',
	'%',
	':',
	' '
};

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

void			print_instr(t_list_node **token, t_list_node **instr, size_t *addr)
{
	int					i;

	while (*token)
	{
		if (((t_token*)(*token)->data)->type == op)
			f_printf("%u :	%s	", *addr, g_ops[((t_token*)(*token)->data)->value.op]);
		else if (((t_token*)(*token)->data)->type == arg)
			f_printf("%c", g_argchar[((t_token*)(*token)->data)->value.op]);
		else if (((t_token*)(*token)->data)->type == number)
			f_printf("%d", ((t_token*)(*token)->data)->value.number);
		else if (((t_token*)(*token)->data)->type == label_arg)
			f_printf(":%s", ((t_token*)(*token)->data)->value.text);
		else if (((t_token*)(*token)->data)->type == separator)
			f_printf("	");
		else if (((t_token*)(*token)->data)->type == eol)
		{
			f_printf("\n");
			break ;
		}
		*token = (*token)->next;
	}
	f_printf("	%d", ((t_instruction*)(*instr)->data)->op);
	i = -1;
	while (++i < g_op_tab[((t_instruction*)(*instr)->data)->op - 1].argc)
	{
		if (((t_instruction*)(*instr)->data)->arg_type[i] == direct)
			*addr += DIR_SIZE - (g_op_tab[((t_instruction*)(*instr)->data)->op - 1].unknown2 << 1);
		else if (((t_instruction*)(*instr)->data)->arg_type[i] == indirect)
			*addr += IND_SIZE;
		else if (((t_instruction*)(*instr)->data)->arg_type[i] == reg)
			*addr += 1;
		f_printf("	%d", ((t_instruction*)(*instr)->data)->arg_value[i]);
	}
	*addr += g_op_tab[((t_instruction*)(*instr)->data)->op - 1].has_encoding_byte;
	(*addr)++;
	*instr = (*instr)->next;
	f_printf("\n\n");
}

void			print_verbose(t_header *header, t_token_list *token_list, t_instr_list *instr_list)
{
	t_list_node		*token;
	t_list_node		*instr;
	size_t			addr;

	f_printf("Dumping annotated program on standard output\n");
	f_printf("Program size : %zu bytes\n", header->prog_size);
	f_printf("Name : \"%s\"\n", header->prog_name);
	f_printf("Comment : \"%s\"\n\n", header->comment);
	token = token_list->head;
	instr = instr_list->head;
	addr = 0;
	while (token)
	{
		if (((t_token*)token->data)->type == label_def)
			f_printf("%zu : %s\n", addr, ((t_token*)token->data)->value.text);
		else if (((t_token*)token->data)->type == eol)
			f_printf("\n");
		else if (((t_token*)token->data)->type == op)
			print_instr(&token, &instr, &addr);
		token = token->next;
	}
}
