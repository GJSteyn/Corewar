/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_token.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:10:23 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/30 14:14:05 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_TOKEN_H
# define S_TOKEN_H

# include <stddef.h>
# include "e_type.h"

struct	s_token
{
	enum e_type		type;
	union u_value	value;
	size_t			line;
};

#endif
