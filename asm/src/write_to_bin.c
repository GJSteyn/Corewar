/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:53:58 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/31 11:32:33 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h> //

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

void	write_data(char bin[MEM_SIZE], char *data ,int *i, int max)
{
	int	x;
	int	tmpi;

	x = 0;
	tmpi = *i;
	while (data[x])
	{
		bin[tmpi] = data[x]; 
		x++;
		tmpi++;
	}
	*i = tmpi + 1;
	write_overflow(bin, i, x, max);
}

void	write_to_bin(char *path, t_header *header)//, t_code *code)
{
	char	bin[MEM_SIZE];
	int		i;
	int		fd;

	fd = open(path, O_RDWR);
	f_little_to_big_endian(header->magic, bin);
	i = 4;
	write_data(bin, header->prog_name, &i, PROG_NAME_LENGTH + 1);
	i++;
	f_little_to_big_endian(header->prog_size, bin + i);
	i += 4;
	write_data(bin, header->comment, &i, COMMENT_LENGTH + 1);
	write(fd, bin, i + 1);
}

int main()
{
	t_header *header;

	header = (t_header*)malloc(sizeof(t_header));
	header->magic = COREWAR_EXEC_MAGIC;
	header->prog_size = 49;
	memcpy(header->prog_name, "IVY\0", 3);
	memcpy(header->comment, "THIS PROGRAMS NAME IS IVY, IN REF TO IVY TOWER\0", 46);
	write_to_bin("test.cor", header);
	return (1);
}

// typedef struct		s_header
// {
// 	unsigned int		magic;
// 	char				prog_name[PROG_NAME_LENGTH + 1];
// 	unsigned int		prog_size;
// 	char				comment[COMMENT_LENGTH + 1];
// }					t_header;

// #endif

// typedef	char t_bin[MEM_SIZE];

// void	f_little_to_big_endian(int little, char big[4])
// {
// 	big[0] = ((unsigned char*)&little)[3];
// 	big[1] = ((unsigned char*)&little)[2];
// 	big[2] = ((unsigned char*)&little)[1];
// 	big[3] = ((unsigned char*)&little)[0];
// }
