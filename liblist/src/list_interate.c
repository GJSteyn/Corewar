/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_interate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 10:11:49 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/29 10:23:01 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_interate(t_list *list, void (*data_mod)(void*))
{
	t_list_node *current;

	current = list->head;
	while (current != NULL)
	{
		data_mod(current->data);
		current = current->next;
	}
}
