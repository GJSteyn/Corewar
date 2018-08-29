/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_clear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 08:55:09 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/28 09:43:49 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "list.h"
#include "f_print.h"
#include "f_string.h"
#include "f_memory.h"
#include <stdlib.h>

static void	del_node(void *data)
{
	f_bzero(data, f_strlen((char*)data));
	free(data);
}

static int	test1(void)
{
	char *data[4];
	t_list *list;
	int i;

	data[0] = f_strdup("asdfl;jhasdf;");
	data[1] = f_strdup("asdfl;jhasf;d&*");
	data[2] = f_strdup("asdfl;kj;ohjasf8");
	data[3] = f_strdup("jkeasdfgniodsf");
	list = list_create(del_node);
	i = -1;
	while (++i < 4)
		list_append(list,	data[i]);
	list_clear(list);
	if (list->size)
		return (0);
	if (list->head || list->tail)
		return (0);
	f_memdel((void**)&list);	
	return (1);
}

int		main(void)
{
	int		(*test[])(void) = {
		&test1, 
		NULL};
	int i  = -1;

	f_print_str("list_create:");	
	while (test[++i])
		if (test[i]())
			f_print_str(" [PASS]");
		else
			f_print_str(" [FAIL]");
	f_print_str("\n");
	return (0);	
}
