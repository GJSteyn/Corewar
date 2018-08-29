/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:54:22 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 17:15:46 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	destroy_label(void *plabel)
{
	t_label *label;

	label = (t_label*)plabel;
	free(label->name);
	free(label);
}

void			*add_label(char *name, size_t offset, int value)
{
	t_label	*label;

	label = (t_label*)malloc(sizeof(t_label));
	*label = (t_label){name, offset, value};
	list_append(get_lable_list(0), label);
}

t_label_list	*glabel_list(int mode)
{
	static t_label_list *list;

	if (!list && mode == LABEL_LIST_INIT)
		list = list_create(destroy_label);
	else if (mode == LABEL_LIST_CLEAR)
	{
		list_clear(list);
		free(list);
		list = NULL;
	}
	return (list);
}

void			*add_dref(char *name, size_t offset)
{
	t_dref_label	*label;

	label = (t_label*)malloc(sizeof(t_label));
	*label = (t_dref_label){name, offset};
	list_append(get_lable_list(0), label);
}

t_label_list	*gdref_list(int mode)
{
	static t_label_list *list;

	if (!list && mode == LABEL_LIST_INIT)
		list = list_create(destroy_label);
	else if (mode == LABEL_LIST_CLEAR)
	{
		list_clear(list);
		free(list);
		list = NULL;
	}
	return (list);
}
