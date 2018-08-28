/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 04:31:24 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/31 20:41:53 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "support/include/f_memory.h"

t_list	*list_create(void (*del_data)(void*))
{
	t_list *list;

	list = (t_list*)f_memalloc(sizeof(*list));
	list_init(list, del_data);
	return (list);
}
