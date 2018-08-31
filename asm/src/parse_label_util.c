/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:54:22 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/31 08:22:31 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void		destroy_label(void *plabel)
{
	t_label *label;

	label = (t_label*)plabel;
	free(label->name);
	free(label);
}

void			*add_glabel(char *name, size_t offset)
{
	t_label	*label;

	label = (t_label*)malloc(sizeof(t_label));
	*label = (t_label){name, offset};
	list_append(lable_list(LABEL_LIST_GET), label);
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

void			*add_gdref(char *name, size_t offset)
{
	t_dref_label	*label;

	label = (t_label*)malloc(sizeof(t_label));
	*label = (t_dref_label){name, offset};
	list_append(gdref_list(LABEL_LIST_GET), label);
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
