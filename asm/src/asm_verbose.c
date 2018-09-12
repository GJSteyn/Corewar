/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_verbose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:15:52 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/12 13:50:06 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "f_print.h"
#include "s_instruction.h"

typedef struct s_instruction	t_instruction;
char		*types[9] = { "keyword", "text", "label_def", "op", "arg", "label_arg", "number", "eol", "separator" };
char		*ops[17] = { "blank", "live", "ld", "st", "add", "sub", "and", "or", "xor", "zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork", "aff" };
char		*args[5] = { "blank", "reg", "direct", "label", "indirect" };

void			print_instructions(t_header *header, t_instr_list *instr_list)
{
	t_instruction	*instr;
	int				i;

	f_printf("HEADER\n	NAME: %7s\n	COMMENT: %7s\n", header->prog_name, header->comment);
	while ((instr = (t_instruction*)list_pop(instr_list, 0)))
	{
		f_printf("OP: %s\n", ops[instr->op]);
		i = -1;
		while (++i < g_op_tab[instr->op - 1].argc)
		{
			f_printf("	ARG: type = %-8s | value = %-7d\n", args[instr->arg_type[i]], instr->arg_value[i]);
		}
		instruction_destroy(instr);
	}
}

void			print_tokens(t_token_list *token_list)
{
	t_token		*t;
	size_t		i;

	i = 0;
	while ((t = DEQUE_TOKEN(token_list)))
	{
		if (t->type == keyword)
		{
			if (t->value.keyword == name)
				f_printf("%zu: %5zu -> %-10s |	[%s]\n", t->line, i++, types[t->type], NAME_CMD_STRING);
			else if (t->value.keyword == comment)
				f_printf("%zu: %5zu -> %-10s |	[%s]\n", t->line, i++, types[t->type], COMMENT_CMD_STRING);
		}
		else if (t->type == text || t->type == label_def || t->type == label_arg)
			f_printf("%zu: %5zu -> %-10s |	[%s]\n", t->line, i++, types[t->type], t->value.text);
		else if (t->type == op)
			f_printf("%zu: %5zu -> %-10s |	[%s]\n", t->line, i++, types[t->type], ops[t->value.op]);
		else if (t->type == number)
			f_printf("%zu: %5zu -> %-10s |	[%d]\n", t->line, i++, types[t->type], t->value.number);
		else if (t->type == eol)
			f_printf("%zu: %5zu -> %-10s |	[%s]\n", t->line, i++, types[t->type], "(null)");
		else if (t->type == arg)
			f_printf("%zu: %5zu -> %-10s |	[%s]\n", t->line, i++, types[t->type], args[t->value.arg]);
		else
			f_printf("%zu: %5zu -> %-10s |	[%s]\n", t->line, i++, types[t->type], NULL);
		token_destroy(&t);
	}
}
