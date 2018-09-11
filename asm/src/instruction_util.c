/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 19:41:29 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/11 16:55:09 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_instruction.h"
#include "f_print.h"
#include <stddef.h>
#include <stdlib.h>

void		instruction_destroy(void *instruction)
{
	free(instruction);
}

void		parse_error(char *err_str, size_t line)
{
	f_fprintf(STDERR, "%s: Line %zu\n", err_str, line);
	exit(1);
}

size_t		goffset(size_t add)
{
	static size_t		offset;

	offset += add;
	return (offset);
}
