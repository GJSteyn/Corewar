/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:50:19 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 19:02:31 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_token.h"

void	destroy_token(struct s_token **token)
{
	free((*token)->value);
	free(*token);
	*token = NULL;
}

void	invalid_token(struct s_token *token, char *message)
{
	f_putnbr_err(token->line);
	f_putstr_err(message);
}
