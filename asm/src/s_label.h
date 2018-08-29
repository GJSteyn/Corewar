/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_label.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:57:19 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 18:05:01 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_LABEL_H
# define S_LABEL_H

# include <stddef.h>

struct	s_label
{
	char	*name;
	size_t	offset;
	int		value;
};

struct	s_dref_label
{
	char	*name;
	size_t	offset;
};

#endif
