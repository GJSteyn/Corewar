/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:55:37 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/27 16:00:51 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_vector.h"
#include "f_memory.h"

void	vector_init(t_vector *vec)
{
	vec->capacity = VECTOR_INIT_CAP;
	vec->total = 0;
	vec->data = f_memalloc(sizeof(void*) * vec->capacity);
}
