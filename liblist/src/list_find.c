/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 08:06:30 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 09:54:00 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	list_find(t_list *list, void *data)
{
	t_list_node *next;
	int			index;

	index = 0;
	next = list->head;
	while (next)
	{
		if (next->data == data)
			return (index);
		next = next->next;
		index++;
	}
	return (-1);
}
