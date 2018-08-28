/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_mergesort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:48:45 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/28 13:35:36 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "support/include/f_memory.h"

static void	split_list(t_list *list, t_list *list_a, t_list *list_b)
{
	int		i;
	void	*data;

	i = 1;
	while ((data = list_pop(list, 0)))
	{
		if (i)
		{
			list_append(list_a, data);
			i = 0;
		}
		else
		{
			list_append(list_b, data);
			i = 1;
		}
	}
}

static void	merge_lists(t_list *sorted, t_list *list_a, t_list *list_b,
												int (*f_data_cmp)(void*, void*))
{
	void *data_a;
	void *data_b;

	data_a = list_pop(list_a, 0);
	data_b = list_pop(list_b, 0);
	while (data_a && data_b)
	{
		if (f_data_cmp(data_a, data_b) < 0)
		{
			list_append(sorted, data_b);
			data_b = list_pop(list_b, 0);
			continue ;
		}
		list_append(sorted, data_a);
		data_a = list_pop(list_a, 0);
	}
	while (list_append(sorted, data_a))
		data_a = list_pop(list_a, 0);
	while (list_append(sorted, data_b))
		data_b = list_pop(list_b, 0);
}

void		list_mergesort(t_list *list, int (*f_data_cmp)(void*, void*))
{
	t_list *list_a;
	t_list *list_b;

	if (list && list->size > 1)
	{
		list_a = list_create(NULL);
		list_b = list_create(NULL);
		split_list(list, list_a, list_b);
		list_mergesort(list_a, f_data_cmp);
		list_mergesort(list_b, f_data_cmp);
		merge_lists(list, list_a, list_b, f_data_cmp);
		list_clear(list_a);
		f_memdel((void**)&list_a);
		list_clear(list_b);
		f_memdel((void**)&list_b);
	}
}
