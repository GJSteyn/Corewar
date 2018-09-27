/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_header_to_bin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 08:04:54 by pstubbs           #+#    #+#             */
/*   Updated: 2018/09/11 09:48:28 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

void	write_overflow(char bin[MEM_SIZE], int *i, int x, int max)
{
	int	tmp;

	tmp = *i;
	while (x <= max)
	{
		bin[tmp] = 0;
		x++;
		tmp++;
	}
	*i = tmp;
}

void	write_data(char bin[MEM_SIZE], char *data, int *i, int max)
{
	int	x;
	int	tmpi;
	int	len;

	x = 0;
	tmpi = *i;
	len = f_strlen(data);
	while (x <= len)
	{
		bin[tmpi] = data[x];
		x++;
		tmpi++;
	}
	*i = tmpi + 1;
	write_overflow(bin, i, x, max);
}

int		write_header_to_bin(char bin[MEM_SIZE], t_header *header)
{
	int		i;

	f_little_to_big_endian(header->magic, bin);
	i = 4;
	write_data(bin, header->prog_name, &i, PROG_NAME_LENGTH + 1);
	i++;
	f_little_to_big_endian(header->prog_size, bin + i);
	i += 4;
	write_data(bin, header->comment, &i, COMMENT_LENGTH + 1);
	return (i + 1);
}
