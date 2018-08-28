/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 07:51:24 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/28 07:57:07 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "f_print.h"
#include "f_memory.h"

int	test1(void)
{
	t_list *list;

	list = list_create(NULL);
	if (sizeof(*list) != sizeof(t_list))
		return(0);
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
