/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:23:25 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/27 16:43:01 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_vector.h"

void		*vector_get(t_vector *vector, size_t index)
{
	if (index < vector->total)
		return (vector->data[index]);
	return (NULL);
}
