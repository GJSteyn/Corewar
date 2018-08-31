/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 19:18:04 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 19:18:34 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_comment(t_token_list *token_list, t_bin bin)
{
	t_token *token;
	char	*comment;
	int		i;

	token = DEQUE_TOKEN(token_list);
	if (token->type != comment || !f_strlen((char *)token->value))
		invalid_token(token, "expected : "COMMENT_CMD_STRING" [Name of bot]\n");
	comment = (char*)token->value;
	bin = bin + MAGIC_SIZE + PROG_NAME_LENGTH;
	i = -1;
	while (i < COMMENT_LENGTH && *comment)
		*bin++ == *comment++;
	destroy_token(&token);
}
