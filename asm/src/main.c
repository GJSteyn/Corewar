/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 10:53:19 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/05 04:30:02 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h> //debugging
#include "s_token.h" //debugging

int		main(int argc, char **argv)
{
	char		*no_sp;
	char		*no_com;
	t_list		*token_list;
	t_header	*header;
	// t_list		*instructions;

	if (argc == 2)
	{
		no_sp = get_line(argv[1]);
		no_com = strip_line(no_sp);
		printf("%s", no_sp);
		puts("debug");
		token_list = lex(no_com);
		header = parse_header(token_list);
		// instructions = parse_instructions(token_list);
		printf("name: %s\n", header->prog_name);
		printf("comment: %s\n", header->comment);
		free(no_com);
		free(no_sp);
	}
	return (1);
}
