/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_op.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 14:56:23 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/07 11:39:39 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_OP_H
# define S_OP_H

#include <stdbool.h>

struct	s_op
{
	char	mnu[5];
	int		argc;
	int		arg_type[3];
	char	bytecode;
	int		cost;
	char	description[64];
	bool	has_encoding;
	bool	direct_index;
};

#endif
