/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:09:09 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/27 16:11:28 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_vector.h"
#include "f_memory.h"

void		vector_free(t_vector *vector)
{
	f_memdel((void**)&(vector->data));
	f_memdel((void**)&vector);
}
