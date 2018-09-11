/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_if.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:39:49 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/11 11:49:58 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

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

void	list_remove_if(t_list *list, bool (*remove_check)(void*))
{
	t_list_node *current;
	t_list_node *temp;
	int			i;

	current = list->head;
	i = -1;
	while (++i && current != NULL)
	{
		if (remove_check(current->data))
		{
			temp = current;
			current = current->next;
			list->f_del_data(temp->data);
			remove_node(list, temp);
			free(temp);
		}
		else
			current = current->next;
	}
}
