/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 21:41:08 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/27 21:42:17 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

typedef char t_bin[CHAMP_MAX_SIZE];

# define MAGIG_SIZE 4
# define HEADER_SIZE MAGIC_SIZE + PROG_NAME_LENGTH + COMMENT_LENGTH + 4

// t_token_list can be replaced by any generic que structure (first in - first out)

typdef struct	s_token
{
	e_type	type;
	void	*value;
	size_t	line;
}				t_token;

void	parse_name(t_token_list token_list, t_bin bin);
void	parse_comment(t_token_list token_list, t_bin bin);

void	parse_header(t_token_list token_list, t_bin bin)
{
	parse_name(token_list, bin);
	parse_comment(token_list, bin);
}

size_t	parse_op(t_token_list token_list, t_bin bin) // this function need to be the branching point to handle each individual op

size_t	parse_code(t_token_list token_list, t_bin bin)
{
	t_token	token;
	size_t	offset;

	offset = HEADER_SIZE;
	while ((token = token_list_deque(token_list)))
	{
		if (!token->type == TK_OP)
			invalid_token();
		offset = parse_op(token_list, bin, offset);
	}
	
}

void	parse(t_token_list token_list, t_bin bin)
{
	parse_header(token_list, bin);
	parse_code(token_list, bin);
	parse_size(bin);
}
