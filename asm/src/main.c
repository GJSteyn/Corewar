/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 10:53:19 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/06 17:02:54 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h> //debugging
#include "s_token.h" //debugging
#include "s_instruction.h"

typedef struct s_instruction	t_instruction;

char	*arg_code[5] = { "arg_blank", "reg", "direct", "label", "indirect" };
char	*keywords[2] = { "name", "comment" };

void	print_type(t_list *token_list)
{
	t_list_node *node = token_list->head;
	t_token		*token;

	while (node)
	{
		token = (t_token*)node->data;
		printf("%zu: ", ((t_token*)node->data)->line);
		if (token->type == 0)
			printf("keyword	-> %s\n", keywords[token->value.keyword]);
		else if (token->type == 1)
			printf("text		-> %s\n", token->value.text);
		else if (token->type == 2)
			printf("label_def	-> %s\n", token->value.text);
		else if (token->type == 3)
			printf("op		-> %s\n", g_op_tab[token->value.op - 1].mnu);
		else if (token->type == 4)
			printf("arg	-> %s\n", arg_code[token->value.arg]);
		else if (token->type == 5)
			printf("label_arg	-> %s\n", token->value.text);
		else if (token->type == 6)
			printf("number	-> %d\n", token->value.number);
		else if (token->type == 7)
			printf("eol\n");
		else if (token->type == 8)
			printf("separator\n");
		node = node->next;
	}
}

void	write_instructions(t_instr_list *instr_list)
{
	t_instruction	*instr;
	int				i;

	while ((instr = (t_instruction*)list_pop(instr_list, 0)))
	{
		i = -1;
		printf("op:		%s\n", g_op_tab[instr->op - 1].mnu);
		printf("arg_type: ");
		while (++i < 3)
			printf("	%s,", arg_code[instr->arg_type[i]]);
		printf("\narg_val: ");
		i = -1;
		while (++i < 3)
			printf("	%d", instr->arg_value[i]);
		printf("\n\n");
	}
}

int		main(int argc, char **argv)
{
	char		*no_sp;
	char		*no_com;
	t_list		*token_list;
	t_header	*header;
	t_list		*instructions;

	if (argc == 2)
	{
		no_sp = get_line(argv[1]);
		// no_com = strip_line(no_sp);
		// printf("%s\n", no_com);
		token_list = lex(no_sp);
		// print_type(token_list);
		header = parse_header(token_list);
		instructions = parse_instructions(token_list, header);
		write_instructions(instructions);
		// printf("name: %s\n", header->prog_name);
		// printf("comment: %s\n", header->comment);
		// free(no_com);
		free(no_sp);
	}
	return (1);
}
