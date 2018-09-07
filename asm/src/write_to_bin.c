/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:53:58 by pstubbs           #+#    #+#             */
/*   Updated: 2018/09/07 10:26:50 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "s_instruction.h"
#include "s_token.h"
typedef struct s_instruction	t_instruction;
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
	f_little_to_big_endian(header->prog_size  - 1, bin + i); // watch -1
	i += 4;
	write_data(bin, header->comment, &i, COMMENT_LENGTH + 1);
	return (i + 1);
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
		printf("[%d]\n", current->arg_type[x]);
		if (current->arg_type[x] == 1)
		{
			ret = ret << 2;
			ret = (ret | 1);
			printf("ret %d [%s]\n", ret ,"reg" );
			
			x++;
			count--;
		}
		else if (current->arg_type[x] == 2)
		{
			ret = ret << 2;
			ret = (ret | 2 );
			printf("ret %d [%s]\n", ret ,"direct" );
			
			x++;
			count--;
		}
		else if(current->arg_type[x] == 4)
		{
			ret = ret << 2;
			ret = (ret | 3);
			
			printf("ret %d [%s]\n", ret ,"indirect" );
			x++;
			count--;
		}
	}
	ret = ret << 2 * count;
	printf("ret %d [%s]\n", ret ,"indirect" );
	bin[*i] = ret;
	*i += 1;
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
	else if (type == 1)	//reg
	{
		bin[tmpi] = c[3];
		tmpi++;
	}
	else if (type == 2) //direc
	{
		bin[tmpi] = c[2];
		bin[tmpi + 1] = c[3];
		tmpi += 2;
	}
		else if (type == 3) //indire
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
	if (type == 2) //direc
	{
		bin[tmpi] = c[0];
		bin[tmpi + 1] = c[1];
		bin[tmpi + 2] = c[2];
		bin[tmpi + 3] = c[3];
		tmpi += 4;
	}
	return (tmpi);
}


// static char	*arg_code[5] = { "arg_blank", "reg", "direct", "label", "indirect" };

void	write_cmd_to_bin(t_instruction *current, char bin[MEM_SIZE], int *i)
{
	int		tmpi;
	int		x;
	int		mod;

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
	// 	if (current->arg_type[x] == 2)
	// 		*i += mod;
		if (current->arg_type[x] == 1)
			tmpi = write_int_to_bytecode(bin, i, 1, current->arg_value[x]);
		// else if (current->arg_type[x] == 2)
		// 	tmpi = write_int_to_bytecode(bin, i, 2, current->arg_value[x]);
		else if (current->arg_type[x] == 2 && g_op_tab[current->op - 1].unknown2 == 1)
			tmpi = write_int_to_bytecode(bin, i, 2, current->arg_value[x]);
		else if (current->arg_type[x] == 2 && g_op_tab[current->op - 1].unknown2 == 0)
			tmpi = write_direct_with_mod(bin, i, 2, current->arg_value[x]);
		else if (current->arg_type[x] == 4)
			tmpi = write_int_to_bytecode(bin, i, 3, current->arg_value[x]);
		*i = tmpi;

	}
	if (g_op_tab[current->op - 1].unknown2 == 1)
			printf("HAS UNKNONWN	\n");
	printf("\n");
	*i = tmpi;
	// *i = tmpi;
	// tmpi = write_int_to_bytecode(bin, i, 1, 2654);
	// *i = tmpi;
}

void	write_to_bin(char *path, t_header *header, t_instr_list *code)
{
	char		bin[MEM_SIZE];
	t_list_node	*current;
	t_instruction	*instr;
	int		fd;
	int		i;

	fd = open(path, O_RDWR);
	f_bzero(bin, MEM_SIZE);
	i = write_header_to_bin(bin, header);
	current = code->head;
	while (current != NULL)
	{
		instr = (t_instruction*)list_pop(code, 0);
		if (instr == NULL)
			break;
		printf("%s\n", g_op_tab[instr->op - 1].mnu); 
		write_cmd_to_bin(instr, bin, &i);
		printf("\n");
		// printf("op:		%u\n", instr->op); //
		free(instr);
	}
	write(fd, bin, i);
}





// look at t_op


// t_op				operation;
// operation.has_encoding_byte;

// t_op.argc



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
