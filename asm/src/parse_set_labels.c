/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_set_labels.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:00:18 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/11 11:51:14 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "f_print.h"

static void		destroy_label(void *plabel)
{
	t_label *label;

	label = (t_label*)plabel;
	free(label->name);
	free(label);
}

static bool		chk_name(void *plabel, void *name)
{
	char *s1;
	char *s2;

	s1 = ((t_dref_label*)plabel)->name;
	s2 = (char*)name;
	while (*s1 && *s2)
	{
		if (*s1++ != *s2++)
			return (0);
		if ((*s1 && !*s2) || (*s2 && !*s1))
			return (0);
	}
	return (true);
}

void			parse_set_labels(void)
{
	t_label_list	*dref_list;
	t_label_list	*label_list;
	t_dref_label	*dref;
	t_label			*label;

	dref_list = gdref_list(LABEL_LIST_GET);
	label_list = glabel_list(LABEL_LIST_GET);
	while ((dref = DEQUE_DREF(dref_list)))
	{
		label = list_func_find(label_list, chk_name, dref->name);
		if (!label)
		{
			f_fprintf(STDERR, "Label: %s does not exist", dref->name);
			exit(1);
		}
		*(dref->value) = label->offset - dref->offset;
		destroy_label(dref);
	}
	gdref_list(LABEL_LIST_CLEAR);
	glabel_list(LABEL_LIST_CLEAR);
}
