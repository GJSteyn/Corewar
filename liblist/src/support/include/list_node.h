/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_node.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 02:02:10 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 09:51:44 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_NODE_H
# define LIST_NODE_H

typedef struct		s_list_node
{
	struct s_list_node	*next;
	struct s_list_node	*prev;
	void				*data;
}					t_list_node;

t_list_node			*list_node_create(t_list_node *prev, t_list_node *next,
											void *data);

#endif
