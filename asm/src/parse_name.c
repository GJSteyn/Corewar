/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 19:16:31 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 19:17:53 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_name(t_token_list *token_list, t_bin bin)
{
	t_token *token;
	char	*name;
	int		i;

	token = DEQUE_TOKEN(token_list);
	if (token->type != name || !f_strlen((char *)token->value))
		invalid_token(token, "expected : "NAME_CMD_STRING" [Name of bot]\n");
	name = (char*)token->value;
	bin = bin + MAGIC_SIZE;
	i = -1;
	while (i < PROG_NAME_LENGTH && *name)
		*bin++ == *name++;
	destroy_token(&token);
}
