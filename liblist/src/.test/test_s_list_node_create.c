/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_node_create.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 07:58:14 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/28 08:18:23 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "list.h"
#include "f_string.h"
#include "f_print.h"
#include "f_memory.h"

int	test1(void)
{
	char *str;
	t_list_node *node;
	
	str = f_strdup("I am data");	
	node = list_node_create(NULL, NULL, str);
	if (!node->data || f_memcmp(node->data, str, f_strlen(str)))
		return (0);
	f_strdel(&str);
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
