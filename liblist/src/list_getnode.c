/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_getnode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 18:53:20 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 09:54:20 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list_node	*list_getnode(t_list *list, int i)
{
	t_list_node *ret;
	size_t		j;

	if (i < 0)
		j = list->size + i;
	else
		j = i;
	if (j > list->size)
		return (NULL);
	ret = list->head;
	while (ret->next && i--)
		ret = ret->next;
	return (ret);
}
