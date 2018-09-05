/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:04:05 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/27 16:42:37 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_vector.h"
#include "f_memory.h"

t_vector	*vector_create(void)
{
	t_vector *vector;

	vector = f_memalloc(sizeof(*vector));
	vector->capacity = VECTOR_INIT_CAP;
	vector->total = 0;
	vector->data = f_memalloc(sizeof(void*) * vector->capacity);
	return (vector);
}
