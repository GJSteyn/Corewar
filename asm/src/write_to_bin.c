/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:53:58 by pstubbs           #+#    #+#             */
/*   Updated: 2018/09/11 08:38:27 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "s_instruction.h"
#include "s_token.h"

typedef struct s_instruction	t_instruction;

void		encoding_byte_body(t_instruction *current, int *ret, int *x, int *count)
{
	if (current->arg_type[*x] == 1)
	{
		*ret = *ret << 2;
		*ret = (*ret | 1);
		(*x)++;
		(*count)--;
	}
	else if (current->arg_type[*x] == 2)
	{
		*ret = *ret << 2;
		*ret = (*ret | 2);
		(*x)++;
		(*count)--;
	}
	else if (current->arg_type[*x] == 4)
	{
		*ret = *ret << 2;
		*ret = (*ret | 3);
		(*x)++;
		(*count)--;
	}
}

void	encoding_byte_to_bin(t_instruction *current, char bin[MEM_SIZE], int *i)
{
	int	x;
	int	ret;
	int count;

	x = 0;
	ret = 0;
	count = 4;
	while (x < g_op_tab[current->op - 1].argc)
	{
		encoding_byte_body(current, &ret, &x, &count);
	}
	ret = ret << 2 * count;
	bin[*i] = ret;
	*i += 1;
}

int		write_int_to_bytecode(char bin[MEM_SIZE], int *i, int type, int data)
{
	char	c[4];
	int		tmpi;

	tmpi = *i;
	f_little_to_big_endian(data, c);
	if (type == 0 || type == 1)
	{
		bin[tmpi] = c[3];
		tmpi++;
	}
	else if (type == 2)
	{
		bin[tmpi] = c[2];
		bin[tmpi + 1] = c[3];
		tmpi += 2;
	}
	else if (type == 4)
	{
		bin[tmpi] = c[2];
		bin[tmpi + 1] = c[3];
		tmpi += 2;
	}
	return (tmpi);
}

int	write_direct_with_mod(char bin[MEM_SIZE], int *i, int type, int data)
{
	char	c[4];
	int		tmpi;

	tmpi = *i;
	f_little_to_big_endian(data, c);
	if (type == 2)
	{
		bin[tmpi] = c[0];
		bin[tmpi + 1] = c[1];
		bin[tmpi + 2] = c[2];
		bin[tmpi + 3] = c[3];
		tmpi += 4;
	}
	return (tmpi);
}

void	write_cmd_to_bin(t_instruction *current, char bin[MEM_SIZE], int *i)
{
	int		tmpi;
	int		x;
	int		mod;
	int		op;

	x = -1;
	mod = 0;
	tmpi = write_int_to_bytecode(bin, i, 0, current->op);
	*i = tmpi;
	if (g_op_tab[current->op - 1].has_encoding_byte == 1)
		encoding_byte_to_bin(current, bin, i);
	if (g_op_tab[current->op - 1].unknown2 == 0)
		mod = 2;
	while (++x < g_op_tab[current->op - 1].argc)
	{
		op = current->arg_type[x];
		if (op == 1 || (op == 2 && g_op_tab[current->op - 1].unknown2 == 1) || op  == 4)
			tmpi = write_int_to_bytecode(bin, i, op, current->arg_value[x]);
		else if (op == 2 && g_op_tab[current->op - 1].unknown2 == 0)
			tmpi = write_direct_with_mod(bin, i, 2, current->arg_value[x]);
		*i = tmpi;
	}
	*i = tmpi;
}

		// op = current->arg_type[x];
		// if (op == 1 || (op == 2 && g_op_tab[current->op - 1].unknown2 == 1) || op  == 4)
		// 	tmpi = write_int_to_bytecode(bin, i, op, current->arg_value[x]);
		// else if (op == 2 && g_op_tab[current->op - 1].unknown2 == 0)
		// 	tmpi = write_direct_with_mod(bin, i, 2, current->arg_value[x]);

void	write_to_bin(char *path, t_header *header, t_instr_list *code)
{
	char			bin[MEM_SIZE];
	t_list_node		*current;
	t_instruction	*instr;
	int				fd;
	int				i;

	fd = open(path, O_CREAT | O_RDWR);
	f_bzero(bin, MEM_SIZE);
	i = write_header_to_bin(bin, header);
	current = code->head;
	while (current != NULL)
	{
		instr = (t_instruction*)list_pop(code, 0);
		if (instr == NULL)
			break ;
		write_cmd_to_bin(instr, bin, &i);
		free(instr);
	}
	write(fd, bin, i);
}
