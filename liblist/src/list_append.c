/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 18:24:25 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/28 13:07:45 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

bool	list_append(t_list *list, void *data)
{
	if (!data)
		return (0);
	if (list->size++)
	{
		list->tail->next = list_node_create(list->tail, NULL, data);
		list->tail = list->tail->next;
	}
	else
	{
		list->head = list_node_create(NULL, NULL, data);
		list->tail = list->head;
	}
	return (1);
}
