/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_label.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:57:19 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/11 11:52:25 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_LABEL_H
# define S_LABEL_H

# include <stddef.h>
# include "list.h"

struct	s_label
{
	char	*name;
	size_t	offset;
};

struct	s_dref_label
{
	char	*name;
	int		*value;
	size_t	offset;
};

typedef	t_list	t_label_list;

#endif
