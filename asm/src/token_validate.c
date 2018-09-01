/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 10:00:15 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/01 12:57:40 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_token.h"
#include "e_type.h"

typedef	enum e_type		t_type;
typedef union u_value	t_value;

int		token_validate(struct s_token *token, t_type type, t_value value)
{
	if (token->type != type)
	{
		f_putstr_err(": Invalid token");
		exit(0);
	}
	if (token->type == text)
	{
		if (value.text && !f_strcmp(value.text, token->value.text))
		{
			f_putstr_err(": Invalid token");
			exit(0);
		}
	}
	else if (token->value.number != value.number)
	{
		f_putstr_err(": Invalid token");
		exit(0);
	}
	return (0);
}
