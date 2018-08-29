/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 10:00:15 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 19:21:58 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_token.h"
#include "e_type.h"

int		vailidate_token(struct s_token *token, enum e_type type)
{
	if (token->type != type)
	{
		f_putstr_err(": Invalid token on line");
		exit(0);
	}
	return (0);
}
