/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 08:06:30 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/13 08:39:48 by wseegers         ###   ########.fr       */
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
