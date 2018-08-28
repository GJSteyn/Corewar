/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 05:20:54 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/28 07:50:56 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_print.h"
#include "f_memory.h"
#include "list.h"

static int	test1(void)
{
	t_list *list;

	list = (t_list*)f_memalloc(sizeof(*list));
	list_init(list, NULL);
	if (list->f_del_data == NULL)
	{
		f_print_err("f_del_data == NULL");
		return (0);
	}
	if (list->head || list->tail)
	{
		f_print_err("list head or tail != NULL");
		return (0);
	}
	list->f_del_data(NULL);
	f_memdel((void**)&list);
	return (1);
}

int		main(void)
{
	int		(*test[])(void) = {
		&test1, 
		NULL};
	int i  = -1;

	f_print_str("list_init:");	
	while (test[++i])
		if (test[i]())
			f_print_str(" [PASS]");
		else
			f_print_str(" [FAIL]");
	f_print_str("\n");
	return (0);	
}

