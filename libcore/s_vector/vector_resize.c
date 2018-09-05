/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:07:49 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/04 07:40:41 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_vector.h"
#include "f_memory.h"

void		vector_resize(t_vector *vector, size_t size)
{
	void **new_data;

	new_data = f_memalloc(sizeof(void*) * size);
	f_memcpy(new_data, vector->data, sizeof(void*) * vector->capacity);
	f_memdel((void**)&vector->data);
	vector->data = new_data;
	vector->capacity *= 2;
}
