/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_set_labels.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:00:18 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/05 00:45:02 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static bool	chk_name(void *plabel, void *name)
{
	char *s1;
	char *s2;

	s1 = ((t_dref_label*)plabel)->name;
	s2 = (char*)name;

	while (*s1 == *s2)
	{
		if (!*s1++)
			return (0);
		s2++;
	}
	return (!((*s1) - (*s2)));
}

void		parse_set_labels(void)
{
	t_label_list	*dref_list;
	t_label_list	*label_list;
	t_dref_label	*dref;
	t_label			*label;
	char			bendian[4];

	dref_list = gdref_list(LABEL_LIST_GET);
	label_list = glabel_list(LABEL_LIST_GET);
	while ((dref = DEQUE_DREF(dref_list)))
	{
		label = list_func_find(label_list, chk_name, dref->name); // catch labels that don't exist
		*(dref->value) = label->offset - dref->offset;
	}
	gdref_list(LABEL_LIST_CLEAR);
	glabel_list(LABEL_LIST_CLEAR);
}
