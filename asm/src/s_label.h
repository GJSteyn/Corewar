/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_label.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:57:19 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/05 08:51:57 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_LABEL_H
# define S_LABEL_H

# include <stddef.h>
# include "list.h"

struct	s_label
{
	char	*name;
	size_t	offset;
};

struct	s_dref_label
{
	char	*name;
	int		*value;
	size_t	offset;
};

typedef	t_list	t_label_list;

// t_label_list	*gdref_list(int mode);
// void			*add_dref(char *name, size_t offset);
// t_label_list	*glabel_list(int mode);
// void			*add_label(char *name, size_t offset);

#endif
