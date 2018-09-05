/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 15:17:22 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/03 13:31:51 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Compile me like this, please:
	gcc lex.c f_get_line.c test.c ../../libcore/src/op.c -L. ../../libcore/libcore.a -I ../../liblist/include -I ../../libcore/include-L. ../../liblist/liblist.a
	I don't like comments (as in '#' comments), because I don't strip lines.
*/

#include <stdio.h>
#include "s_token.h"
#include "list.h"
#include "asm.h"
#include "op.h"
#include <stdlib.h>

char			*f_get_line(char *path);
t_list			*lex(char *clean_line);

typedef struct s_token		t_token;

char	*keywords[2] = { "name", "comment" };
char	*arg_code[5] = { "arg_blank", "reg", "direct", "indirect", "label" };

void	print_type(t_token *token)
{
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
}

int		main(int argc, char **argv)
{
	char		*no_sp;
	t_list		*list;
	t_list_node *node;

	if (argc == 2)
	{
		no_sp = get_line(argv[1]);
		list = lex(no_sp);
		free(no_sp);

		node = list->head;
		while (node)
		{
			printf("%zu: ", ((t_token*)node->data)->line);
			print_type((t_token*)node->data);
			node = node->next;
		}
	}
	return (1);
}
