/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 10:53:19 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/01 14:32:56 by pstubbs          ###   ########.fr       */
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

	if (argc == 2)
	{
		no_sp = get_line(argv[1]);
		no_com = strip_line(no_sp);
		token_list = lex(no_com);
		header = parse_header(token_list);
		header->prog_size = 23;
		free(no_com);
		free(no_sp);
		write_to_bin("/goinfre/pstubbs/Documents/Corewar/asm/src/test.cor", header);
	}
	return (1);
}
