/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 12:52:06 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 09:52:53 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	rot_fw(t_list *list)
{
	void	*first;

	first = list_pop(list, 0);
	list_append(list, first);
}

static void	rot_bk(t_list *list)
{
	void	*last;

	last = list_pop(list, -1);
	list_insert(list, last, 0);
}

void		list_rot(t_list *list, int n)
{
	if (n == 0 || list->size < 2)
		return ;
	while (n > 0 && n--)
		rot_fw(list);
	while (n++ < 0)
		rot_bk(list);
}
