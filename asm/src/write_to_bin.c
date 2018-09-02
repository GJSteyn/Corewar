/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:53:58 by pstubbs           #+#    #+#             */
/*   Updated: 2018/09/02 13:09:14 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h> //


void	print_bits(unsigned char octec)
{
	int i = 256;
	while(i >>=1)
	{
		(octec & i) ? write(1,"1",1) : write(1, "0", 1);
	}
	write(1, " ", 1);
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

int		write_header_to_bin(char bin[MEM_SIZE], t_header *header)//, t_code *code)
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

int		write_int_to_bytecode(char bin[MEM_SIZE], int *i, int type, int data)
{
	char	c[4];
	int		tmpi;

	tmpi = *i;
	f_little_to_big_endian(data, c);
	if (type == 0)	//opcode
	{
		bin[tmpi] = c[3];
		tmpi++;
	}
	else if (type == 1)
	{
		bin[tmpi] = c[2];
		bin[tmpi + 1] = c[3];
		tmpi += 2;
	}
	return (tmpi);
}

void	write_cmd_to_bin(t_list_node *current ,char bin[MEM_SIZE], int *i)
{
	int		tmpi;

	tmpi = write_int_to_bytecode(bin, i, 0, current->data->opcode);
	*i = tmpi;
	tmpi = write_int_to_bytecode(bin, i, 1, 2654);
	*i = tmpi;
}

void	write_to_bin(char *path, t_header *header, t_list *code)
{
	char		bin[MEM_SIZE];
	t_list_node *current;
	int		fd;
	int		i;

	fd = open(path, O_RDWR);
	f_bzero(bin, MEM_SIZE);
	i = write_header_to_bin(bin, header);
	current = code->head;
	while (current != NULL)
	{
		write_cmd_to_bin(current ,bin, &i);
		current = current->next;
	}
	write(fd, bin, i);
}

// int main()
// {
// 	t_header *header;

// 	header = (t_header*)malloc(sizeof(t_header));
// 	header->magic = COREWAR_EXEC_MAGIC;
// 	header->prog_size = 49;
// 	memcpy(header->prog_name, "IVY\0", 3);
// 	memcpy(header->comment, "THIS PROGRAMS NAME IS IVY, IN REF TO IVY TOWER\0", 46);
// 	write_to_bin("test.cor", header);

// 	// int	t = 2;
// 	char c;
// 	f_little_to_big_endian(2, &c);

// 	print_bits(((unsigned char*)&c)[0]);
// 	print_bits(((unsigned char*)&c)[1]);
// 	print_bits(((unsigned char*)&c)[2]);
// 	print_bits(((unsigned char*)&c)[3]);
// 	// write(1, "\n", 1);

// 	// if (((unsigned char*)&c)[0] & 255)



// 	return (1);
// }
