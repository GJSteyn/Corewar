/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 10:53:19 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/17 08:43:31 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "f_print.h"

char	*path_output(char *path)
{
	char	*ret;
	int		i;

	i = f_strlen(path);
	while (i > 0 && path[i] != '.')
		i--;
	if (i > 0)
		ret = f_strsub(path, 0, i);
	else
		ret = f_strdup(path);
	ret = f_dynamicstring(&ret, ".cor");
	return (ret);
}

void	destroy_asm(char *path, t_header *head, t_list *instr, t_list *tk_lst)
{
	if (tk_lst)
	{
		list_clear(tk_lst);
		free(tk_lst);
	}
	if (head)
		free(head);
	if (instr)
	{
		list_clear(instr);
		free(instr);
	}
	if (path)
		free(path);
}

int		asm_options(char **av, int *i)
{
	int	ret;
	int	len;
	int	x;

	x = 0;
	ret = 0;
	while (av[x])
	{
		len = f_strlen(av[x]);
		if (av[x][0] == '-' && av[x][1] == 'a' && len == 2)
			ret = 1;
		if (av[x + 1] == NULL && av[x][0] == '-' && av[x][1] != 'a' && len == 2)
			return (-1);
		else if (av[x][0] != '-' && len > 2)
			*i = x;
		x++;
	}
	return (ret);
}

void	asm_output(char **argv, int i, int ops)
{
	char		*no_sp;
	t_list		*instructions;
	t_list		*token_list;
	t_header	*header;

	no_sp = get_line(argv[i]);
	token_list = lex(no_sp);
	header = parse_header(token_list);
	instructions = parse_instructions(token_list, header);
	if (ops == 1)
		print_verbose(header, token_list, instructions);
	else if (ops == 0)
	{
		free(no_sp);
		no_sp = path_output(argv[i]);
		write_to_bin(no_sp, header, instructions);
		f_printf("Bot:'%s' was created! Bot size:|%d| bytes.\n",
		header->prog_name, header->prog_size);
	}
	destroy_asm(no_sp, header, instructions, token_list);
}

int		main(int argc, char **argv)
{
	int			ops;
	int			i;

	if (argc >= 2)
	{
		ops = asm_options(argv, &i);
		if (ops < 0)
			f_printf("Invaild flag\n");
		else
			asm_output(argv, i, ops);
	}
	else
	{
		f_printf("Usage: %s [-a] <sourcefile.s>\n	-a : %s", argv[0],
		"Instead of creating a .cor file, outputs a stripped and annotated"
		"version of the code to the standard output\n");
	}
	return (1);
}
