/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 21:41:08 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 10:00:12 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"


# define MAGIC_SIZE 4
# define HEADER_SIZE MAGIC_SIZE + PROG_NAME_LENGTH + COMMENT_LENGTH + 4

// t_token_list can be replaced by any generic que structure (first in - first out)

void	parse_name(t_token_list *token_list, t_bin bin)
{
	t_token *name;
	t_token *text;

	name = DEQUE_TOKEN(token_list);
	text = DEQUE_TOKEN(token_list);

	bin = bin + MAGIC_SIZE;

}

void	parse_comment(t_token_list *token_list, t_bin bin)
{

}

void	parse_header(t_token_list *token_list, t_bin bin)
{
	parse_name(token_list, bin);
	parse_comment(token_list, bin);

}

size_t	parse_code(t_token_list *token_list, t_bin bin)
{
	t_token	*token;
	size_t	offset;

	offset = HEADER_SIZE;
	while ((token = token_list_deque(token_list)))
	{
		if (!token->type == op)
			invalid_token();  //require invalid_token function
		offset = g_op_func[*(int*)token->value](token_list, bin, offset);
	}
}

void	parse(t_token_list *token_list, t_bin bin)
{
	parse_header(token_list, bin);
	parse_code(token_list, bin);
	parse_size(bin);
}
