/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:52:14 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 09:51:02 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*list_copy(t_list *orig)
{
	t_list	*copy;
	size_t	i;

	copy = list_create(orig->f_del_data);
	i = -1;
	while (++i < orig->size)
		list_append(copy, list_get(orig, i));
	return (copy);
}
