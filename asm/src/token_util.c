/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:50:19 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/10 18:14:21 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_token.h"
#include <stdio.h> //debugging

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
	//f_putnbr_err(token->line);
	//f_putstr_err(message);

	(void)token;
	printf("Invalid token: %s\n", message);
}
