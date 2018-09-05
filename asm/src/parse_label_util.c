/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:54:22 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/05 05:20:37 by gsteyn           ###   ########.fr       */
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

void			add_glabel(char *name, size_t offset)
{
	t_label	*label;

	label = (t_label*)malloc(sizeof(t_label));
	*label = (t_label){name, offset};
	list_append(glabel_list(LABEL_LIST_GET), label);
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

void			add_gdref(char *name, int *value, size_t offset)
{
	t_dref_label	*label;

	label = (t_dref_label*)malloc(sizeof(t_dref_label));
	*label = (t_dref_label){name, value, offset};
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
