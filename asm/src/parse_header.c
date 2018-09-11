/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 08:06:00 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/11 13:53:20 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "f_print.h"

typedef	enum e_type		t_type;
typedef union u_value	t_value;

static size_t	parse_eol(t_token_list *token_list)
{
	t_token *token;
	size_t	nr;

	nr = 0;
	while (PEEK_TOKEN(token_list)->type == (t_type)eol)
	{
		token = DEQUE_TOKEN(token_list);
		token_destroy(&token);
		nr++;
	}
	return (nr);
}

static void		parse_comment(t_token_list *token_list, t_header *header)
{
	t_token *token;
	t_value chk_value;

	chk_value.keyword = comment;
	token_validate((token = DEQUE_TOKEN(token_list)), (t_type)keyword,
		chk_value);
	token_destroy(&token);
	chk_value.text = NULL;
	token_validate((token = DEQUE_TOKEN(token_list)), (t_type)text, chk_value);
	f_strncpy(header->comment, token->value.text, COMMENT_LENGTH);
	token_destroy(&token);
	if (parse_eol(token_list) < 1)
	{
		f_printf("expected eol\n");
		exit(1);
	}
}

static void		parse_name(t_token_list *token_list, t_header *header)
{
	t_token *token;
	t_value chk_value;

	chk_value.keyword = name;
	token_validate((token = DEQUE_TOKEN(token_list)), (t_type)keyword,
		chk_value);
	token_destroy(&token);
	chk_value.text = NULL;
	token_validate((token = DEQUE_TOKEN(token_list)), (t_type)text, chk_value);
	f_strncpy(header->prog_name, token->value.text, PROG_NAME_LENGTH);
	token_destroy(&token);
	if (parse_eol(token_list) < 1)
	{
		f_printf("expected eol\n");
		exit(1);
	}
}

t_header		*parse_header(t_token_list *token_list)
{
	t_header *header;

	header = (t_header*)malloc(sizeof(t_header));
	header->magic = COREWAR_EXEC_MAGIC;
	parse_eol(token_list);
	parse_name(token_list, header);
	parse_comment(token_list, header);
	return (header);
}
