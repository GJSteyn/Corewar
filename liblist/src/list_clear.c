/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 18:12:28 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/28 09:26:20 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "support/include/f_memory.h"

void	list_clear(t_list *list)
{
	t_list_node	*cur;
	t_list_node	*del;

	cur = list->head;
	while (cur)
	{
		del = cur;
		cur = cur->next;
		list->f_del_data(del->data);
		del->data = NULL;
		f_memdel((void**)&del);
	}
	list->size = 0;
	list_init(list, list->f_del_data);
}
