/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_op.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 14:56:23 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/05 02:00:58 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_OP_H
# define S_OP_H

# include <stdbool.h>

struct	s_op
{
	char	mnu[5];
	int		argc;
	int		arg_type[3];
	char	bytecode;
	int		cost;
	char	description[64];
	int		has_encoding_byte;
	int		unknown2;
};

#endif
