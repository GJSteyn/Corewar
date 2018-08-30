/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writetobyte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:53:58 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/30 14:14:21 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h> //



void	write_to_bin(char *path, t_header *header)//, t_code *code)
{
	char	bin[MEM_SIZE];
	char	*name;
	char	*comment;
	int	t;
	int	i;
	int	fd;

	fd = open("test.cor", O_RDWR);
	name = header->prog_name;
	comment = header->comment;
	f_little_to_big_endian(header->magic, bin);
	i = 4;
	while (*name)
	{
		f_little_to_big_endian(*name, bin + i);
		// printf("[%c]", (*name));
		name++;
		i += 4;
	}
	while (*comment)
	{
		f_little_to_big_endian(*comment, bin + i);
		comment++;
		i += 4;
	}
	// printf("[%c]\n",bin[4] );
	write(fd, bin, i);
}

int main()
{
	t_header *header;

	header = (t_header*)malloc(sizeof(t_header));
	header->magic = 6548932;
	memcpy(header->prog_name, "IVY\0", 3);
	memcpy(header->comment, "THIS PROGRAMS NAME IS IVY, IN REF TO IVY TOWER\0", 46);
	write_to_bin(NULL, header);
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
