/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 10:58:44 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/11 09:48:35 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

# include "core.h"
# include "op.h"
# include "list.h"

# include "parse.h"

char	*strip_line(char *line);
char	*get_line(char *path);
t_list	*lex(char *clean_line);
void	write_to_bin(char *path, t_header *header, t_instr_list *code);
int		write_header_to_bin(char bin[MEM_SIZE], t_header *header);
int		write_int_to_bytecode(char bin[MEM_SIZE], int *i, int type, int data);

#endif
