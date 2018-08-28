/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_pop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:19:13 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/28 13:58:29 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "f_print.h"
#include "f_string.h"
#include "f_memory.h"

int 	test1(void)
{
	char *data[4];
	t_list *list;
	void *data_pop;
	int i;

	data[0] = f_strdup("asdfl;jhasdf;\n");
	data[1] = f_strdup("asdfl;jhasf;d&*\n");
	data[2] = f_strdup("asdfl;kj;ohjasf8\n");
	data[3] = f_strdup("jkeasdfgniodsf\n");
	list = list_create(NULL);
	i = -1;
	while (++i < 4)
		list_append(list,	data[i]);
	i = -1;
	f_print_str("\n");
	while (++i < 4)
	{
		data_pop = list_pop(list, 0);
		if (f_memcmp(data_pop, data[i], f_strlen(data[i])))
				return (0);
		f_memdel(&data_pop);
	}
	if (list->tail || list->head)
		return (0);
	list_clear(list);
	return (1);
}

int 	test2(void)
{
	char *data[4];
	t_list *list;
	void *data_pop;
	int i;

	data[0] = f_strdup("0 asdfl;jhasdf;");
	data[1] = f_strdup("1 asdfl;jhasf;d&*");
	data[2] = f_strdup("2 asdfl;kj;ohjasf8");
	data[3] = f_strdup("3 jkeasdfgniodsf");
	list = list_create(NULL);
	i = -1;
	while (++i < 4)
		list_append(list,	data[i]);
	i = 4;
	while (i--)
	{
		data_pop = list_pop(list, -1);
		if (f_memcmp(data_pop, data[i], f_strlen(data[i])))
				return (0);
		f_memdel(&data_pop);
	}
	if (list->tail || list->head)
		return (0);
	list_clear(list);
	return (1);
}

int 	test3(void)
{
	char *data[8];
	t_list *list;
	int i;

	data[0] = f_strdup("0 asdfl;jhasdf;");
	data[1] = f_strdup("1 asdfl;jhasf;d&*");
	data[2] = f_strdup("2 asdfl;kj;ohjasf8");
	data[3] = f_strdup("3 jkeasdfgniodsf");
	data[4] = f_strdup("4 jkeasdfgniodsf");
	data[5] = f_strdup("5 jkeasdfgniodsf");
	data[6] = f_strdup("6 jkeasdfgniodsf");
	data[7] = f_strdup("7 jkeasdfgniodsf");
	list = list_create(NULL);
	i = -1;
	while (++i < 8)
		list_append(list,	data[i]);
	if (list_pop(list, 5) != data[5])
		return (0);
	if (list_pop(list, 2) != data[2])
		return (0);
	if (list_pop(list, -2) != data[6])
		return (0);
	i = 0;
	while (list_pop(list, -1))
		i++;
	if (i != 5)
		return (0);
	list_clear(list);
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
