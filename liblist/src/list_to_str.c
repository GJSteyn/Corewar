/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 10:00:53 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 09:52:37 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "support/include/list_node.h"
#include "support/include/f_string.h"

char	*list_tostr(t_list *list, char divider, char *(to_str)(void*))
{
	t_list_node *node;
	char		*next;
	char		*ret;
	char		*join;

	if (!(node = list->head))
		return (f_strnew(1));
	ret = f_strdup(to_str(node->data));
	node = node->next;
	while (node)
	{
		next = to_str(node->data);
		join = f_strcjoin(ret, next, divider);
		f_strdel(&ret);
		ret = join;
		node = node->next;
	}
	return (ret);
}
