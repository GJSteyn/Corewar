/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 04:52:20 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 09:51:52 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	*list_func_find(t_list *list, bool (*chk)(void*, void*),
															void *chk_data)
{
	t_list_node	*cur;

	cur = list->head;
	while (cur)
	{
		if (chk(cur->data, chk_data))
			return (cur->data);
		cur = cur->next;
	}
	return (NULL);
}
