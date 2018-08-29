/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:56:43 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 09:53:55 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "support/include/f_math.h"

static void	*get_head(t_list *list, size_t i)
{
	t_list_node	*node;
	void		*data;

	node = list->head;
	while (i--)
		node = node->next;
	data = node->data;
	return (data);
}

static void	*get_tail(t_list *list, size_t i)
{
	t_list_node	*node;
	void		*data;

	node = list->tail;
	while (--i)
		node = node->prev;
	data = node->data;
	return (data);
}

void		*list_get(t_list *list, int index)
{
	int		size_i;

	size_i = list->size;
	if (list->size == 0)
		return (NULL);
	if (index >= size_i || -index > size_i)
		return (NULL);
	if (index < 0)
		return (get_tail(list, f_abs(index)));
	else
		return (get_head(list, f_abs(index)));
}
