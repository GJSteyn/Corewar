/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_token.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:10:23 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 19:12:10 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_TOKEN_H
# define S_TOKEN_H

# include <stdlib.h>
# include <stddef.h>

# include "e_type.h"
# include "core.h"

struct	s_token
{
	enum e_type	type;
	void		*value;
	size_t		line;
};

void	destroy_token(struct s_token **token);

#endif
