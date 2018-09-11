/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 21:41:08 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/31 09:20:17 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

size_t	parse_op(t_op op, t_token_list *token_list, t_bin bin)
{
	char	*encode;
	int		i;

	encode = NULL;
	bin[offset++] = op.bytecode;
	if (op.argc > 1)
	{
		encode = bin + offset;
		offset++;
	}
	i = -1;
	while (i++ < op.argc)
		offset = parse_arg(op.arg_type[i], token_list, bin, offset);
	return (offset);
}

size_t	parse_code(t_token_list *token_list, t_code_list code_list)
{
	t_token	*token;
	size_t	offset;

	offset = HEADER_SIZE;
	while ((token = DEQUE_TOKEN(token_list)))
	{
		if (token->type == label)
		{
			add_label(f_strdup(token->value), offset);
			destroy_token(&token);
			token = DEQUE_TOKEN(token_list);
		}
		if (!token->type == op)
			invalid_token(token, "");
		offset = parse_op(g_op_tab[*(int*)(token->value)],
					token_list, bin, offset);
	}
}

void	parse(t_token_list *token_list, t_bin bin)
{
	parse_name(token_list, bin);
	parse_comment(token_list, bin);
	glabel_list(LABEL_LIST_INIT);
	gdref_list(LABEL_LIST_INIT);
	parse_code(token_list, bin);
	parse_size(bin);
}
