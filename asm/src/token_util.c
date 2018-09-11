/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:50:19 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/11 12:55:46 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_token.h"
#include "f_print.h"

void	token_destroy(struct s_token **token)
{
	if ((*token)->type == text || (*token)->type == label_arg ||
												(*token)->type == label_def)
		free((*token)->value.text);
	free(*token);
	*token = NULL;
}

void	invalid_token(struct s_token *token, char *message)
{
	(void)token;
	f_printf("Invalid token: %s\n", message);
}
