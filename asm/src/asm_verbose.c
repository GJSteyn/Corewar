/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_verbose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:15:52 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/27 11:33:31 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "f_print.h"
#include "s_instruction.h"
#include "list.h"
#include "asm.h"

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

static void		print_token(t_list_node **token, size_t addr)
{
	while (*token)
	{
		if (((t_token*)(*token)->data)->type == op)
			f_printf("%u :	%s	", addr,
					g_ops[((t_token*)(*token)->data)->value.op]);
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
}

static void		print_instr(t_list_node **instr, size_t *addr)
{
	int			i;
	char		bin;

	i = 0;
	encoding_byte_to_bin(((t_instruction*)(*instr)->data), &bin, &i);
	f_printf("	%d", ((t_instruction*)(*instr)->data)->op);
	if (g_op_tab[((t_instruction*)(*instr)->data)->op - 1].has_encoding)
		f_printf(" %hhu", bin);
	i = -1;
	while (++i < g_op_tab[((t_instruction*)(*instr)->data)->op - 1].argc)
	{
		if (((t_instruction*)(*instr)->data)->arg_type[i] == direct)
			*addr += DIR_SIZE -
		(g_op_tab[((t_instruction*)(*instr)->data)->op - 1].direct_index << 1);
		else if (((t_instruction*)(*instr)->data)->arg_type[i] == indirect)
			*addr += IND_SIZE;
		else if (((t_instruction*)(*instr)->data)->arg_type[i] == reg)
			*addr += 1;
		f_printf("	%d", ((t_instruction*)(*instr)->data)->arg_value[i]);
	}
	*addr += g_op_tab[((t_instruction*)(*instr)->data)->op
						- 1].has_encoding;
	*instr = (*instr)->next;
	f_printf("\n\n");
}

void			print_verbose(t_header *header, t_token_list *token_list,
								t_instr_list *instr_list)
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
		{
			print_token(&token, addr);
			print_instr(&instr, &addr);
			addr++;
		}
		token = token->next;
	}
}
