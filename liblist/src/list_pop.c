/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 10:04:24 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/28 13:25:30 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "support/include/f_memory.h"
#include "support/include/f_math.h"

static void			remove_node(t_list *list, t_list_node *node)
{
	if (node->prev && node->next)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	else if (node->next)
	{
		list->head = node->next;
		node->next->prev = NULL;
	}
	else if (node->prev)
	{
		list->tail = node->prev;
		node->prev->next = NULL;
	}
	else
	{
		list->tail = NULL;
		list->head = NULL;
	}
}

static void			*pop_head(t_list *list, size_t i)
{
	t_list_node	*node;
	void		*data;

	node = list->head;
	while (i--)
		node = node->next;
	data = node->data;
	remove_node(list, node);
	f_memdel((void**)&node);
	return (data);
}

static void			*pop_tail(t_list *list, size_t i)
{
	t_list_node	*node;
	void		*data;

	node = list->tail;
	while (--i)
		node = node->prev;
	data = node->data;
	remove_node(list, node);
	f_memdel((void**)&node);
	return (data);
}

void				*list_pop(t_list *list, int index)
{
	int		size_i;

	size_i = list->size;
	if (list->size == 0)
		return (NULL);
	if (index >= size_i || -index > size_i)
		return (NULL);
	--list->size;
	if (index < 0)
		return (pop_tail(list, f_abs(index)));
	else
		return (pop_head(list, f_abs(index)));
}
