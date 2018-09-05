/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:26:44 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/27 16:30:24 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_vector.h"

void		*vector_remove(t_vector *vector, size_t index)
{
	void *ret;

	if (index >= vector->total)
		return (NULL);
	ret = vector->data[index];
	while (index < vector->total - 1)
	{
		vector->data[index] = vector->data[index + 1];
		index++;
	}
	vector->data[index] = NULL;
	vector->total = index;
	return (ret);
}
