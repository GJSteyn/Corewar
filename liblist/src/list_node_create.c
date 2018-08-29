/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_node_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 18:31:23 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 09:53:42 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "support/include/f_memory.h"

t_list_node	*list_node_create(t_list_node *prev, t_list_node *next,
																void *data)
{
	t_list_node *node;

	if ((node = f_memalloc(sizeof(*node))))
	{
		node->prev = prev;
		node->next = next;
		node->data = data;
	}
	return (node);
}
