/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 10:53:19 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/05 10:25:26 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h> //debugging
#include "s_token.h" //debugging
#include "s_instruction.h"

typedef struct s_instruction	t_instruction;

char	*arg_code[5] = { "arg_blank", "reg", "direct", "label", "indirect" };

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
		no_com = strip_line(no_sp);
		token_list = lex(no_com);
		header = parse_header(token_list);
		instructions = parse_instructions(token_list, header);
		write_instructions(instructions);
		// printf("name: %s\n", header->prog_name);
		// printf("comment: %s\n", header->comment);
		free(no_com);
		free(no_sp);
		write_to_bin("/goinfre/pstubbs/Documents/Corewar/asm/src/test.cor", header);
	}
	return (1);
}
