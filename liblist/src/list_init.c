/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:56:49 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 09:53:49 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	del_data_placeholder(void *data)
{
	(void)data;
}

void	list_init(t_list *list, void (*del_data)(void*))
{
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	list->f_del_data = del_data;
	if (list->f_del_data == NULL)
		list->f_del_data = &del_data_placeholder;
}
