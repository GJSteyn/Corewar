/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 02:01:15 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/11 11:50:53 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
# include "../src/support/include/list_node.h"

typedef struct		s_list
{
	t_list_node			*head;
	t_list_node			*tail;
	size_t				size;
	void				(*f_del_data)(void*);
}					t_list;

void				list_init(t_list *list, void (*del_data)(void*));
char				*list_tostr(t_list *list, char divider,
						char *(to_str)(void*));
t_list				*list_create(void (*del_data)(void*));
bool				list_append(t_list *list, void *data);
void				list_insert(t_list *list, void *data, int i);
void				list_clear(t_list *list);
void				*list_pop(t_list *list, int index);
t_list_node			*list_getnode(t_list *list, int i);
void				list_rot(t_list *list, int n);
void				*list_get(t_list *list, int index);
t_list				*list_copy(t_list *orig);
int					list_find(t_list *list, void *data);
void				list_mergesort(t_list *list,
									int (*f_data_cmp)(void*, void*));
void				*list_func_find(t_list *list,
									bool (*chk)(void*, void*), void *chk_data);
void				list_iterate(t_list *list, void (*data_mod)(void**));

#endif
