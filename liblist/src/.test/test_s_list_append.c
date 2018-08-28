/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_append.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 08:19:29 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/28 12:37:27 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "f_print.h"
#include "f_string.h"
#include "f_memory.h"

int		test1(void)
{
	char *data;
	t_list *list;

	data = f_strdup("I am data");
	list = list_create(NULL);
	list_append(list,	data);

	if (f_memcmp(list->head->data, data, f_strlen(data)))
		return (0);
	if (f_memcmp(list->tail->data, data, f_strlen(data)))
		return (0);
	if (list->size != 1)
		return (0);
	f_strdel(&data);
	f_memdel((void**)list->head);
	f_memdel((void**)list);
	return (1);
}

int 	test2(void)
{
	char *data[4];
	t_list *list;
	t_list_node *node;
	int i;

	data[0] = f_strdup("asdfl;jhasdf;");
	data[1] = f_strdup("asdfl;jhasf;d&*");
	data[2] = f_strdup("asdfl;kj;ohjasf8");
	data[3] = f_strdup("jkeasdfgniodsf");
	list = list_create(NULL);
	i = -1;
	while (++i < 4)
		list_append(list,	data[i]);
	if (list->size != 4)
		return (0);
	if (f_memcmp(list->head->data, data[0], f_strlen(data[0])))
		return (0);
	if (f_memcmp(list->tail->data, data[3], f_strlen(data[3])))
		return (0);
	node = list->head;
	i = -1;
	while (node && ++i < 4)
	{
		if (f_memcmp(node->data, data[i], f_strlen(data[i])))
			return (0);
		node = node->next;
	}
	i = -1;
	while (++i < 4)
		f_strdel(&data[i]);
	node = list->head;
	while (node)
	{
		if (node->prev)
			f_memdel((void**)&node->prev);
		node = node->next;
	}
	f_memdel((void**)&node);
	f_memdel((void**)&list);
	return (1);
}

int 	test3(void)
{
	char *data[4];
	t_list *list;
	t_list_node *node;
	int i;

	data[0] = f_strdup("asdfl;jhasdf;");
	data[1] = f_strdup("asdfl;jhasf;d&*");
	data[2] = f_strdup("asdfl;kj;ohjasf8");
	data[3] = f_strdup("jkeasdfgniodsf");
	list = list_create(NULL);
	i = -1;
	while (++i < 4)
		list_append(list,	data[i]);
	node = list->tail;
	if (node->next)
		return (0);
	i = 1;
	while (node->prev)
	{
		i++;
		node = node->prev;
	}
	if (i < 4)
		return(0);
	return (1);
}

int		main(void)
{
	int		(*test[])(void) = {
		&test1, 
		&test2,
		&test3,
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
