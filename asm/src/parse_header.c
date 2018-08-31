/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 08:06:00 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/31 09:17:16 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

typedef	enum e_type		t_type;
typedef union u_value	t_value;

static void	parse_comment(t_token_list *token_list, t_header *header)
{
	t_token *token;
	char	*name;
	int		i;
	t_value chk_value;

	chk_value.keyword = comment;
	vailidate_token((token = DEQUE_TOKEN(token_list)), (t_type)keyword,
		chk_value);
	destroy_token(&token);
	chk_value.text = NULL;
	vailidate_token((token = DEQUE_TOKEN(token_list)), (t_type)text, chk_value);
	f_strncpy(header->comment, token->value.text, COMMENT_LENGTH);
	destroy_token(&token);
}

static void	parse_name(t_token_list *token_list, t_header *header)
{
	t_token *token;
	char	*name;
	int		i;
	t_value chk_value;

	chk_value.keyword = name;
	vailidate_token((token = DEQUE_TOKEN(token_list)), (t_type)keyword,
		chk_value);
	destroy_token(&token);
	chk_value.text = NULL;
	vailidate_token((token = DEQUE_TOKEN(token_list)), (t_type)text, chk_value);
	f_strncpy(header->prog_name, token->value.text, PROG_NAME_LENGTH);
	destroy_token(&token);
}

t_header	*parse_header(t_token_list *token_list)
{
	t_header *header;

	header = (t_header*)malloc(sizeof(t_header));
	header->magic = COREWAR_EXEC_MAGIC;
	parse_name(token_list, header);
	parse_comment(token_list, header);
}
