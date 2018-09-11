/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 10:53:19 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/11 11:48:17 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*path_output(char *path)
{
	char	*ret;

	ret = f_strsub(path, 0, f_strlen(path) - 1);
	ret = f_dynamicstring(&ret, "cor");
	return (ret);
}

int		main(int argc, char **argv)
{
	char		*no_sp;
	char		*path;
	t_list		*token_list;
	t_header	*header;
	t_list		*instructions;

	if (argc == 2)
	{
		no_sp = get_line(argv[1]);
		token_list = lex(no_sp);
		header = parse_header(token_list);
		instructions = parse_instructions(token_list, header);
		free(no_sp);
		path = path_output(argv[1]);
		write_to_bin(path, header, instructions);
		free(token_list);
		free(header);
		free(instructions);
		free(path);
	}
	return (1);
}
