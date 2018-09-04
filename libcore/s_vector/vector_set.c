/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:20:41 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/27 16:44:39 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_vector.h"

void		vector_set(t_vector *vector, size_t index, void *item)
{
	if (index < vector->total)
		vector->data[index] = item;
}
