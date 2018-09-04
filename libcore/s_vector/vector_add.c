/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:17:02 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/27 16:40:49 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_vector.h"

void		vector_add(t_vector *vector, void *item)
{
	if (vector->total == vector->capacity)
		vector_resize(vector, vector->capacity * 2);
	vector->data[vector->total++] = item;
}
