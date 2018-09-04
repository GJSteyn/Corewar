/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vector.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:47:26 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/04 10:22:37 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_VECTOR_H
# define S_VECTOR_H

# include <stddef.h>

# define VECTOR_INIT_CAP 8;

typedef struct	s_vector
{
	void	**data;
	size_t	total;
	size_t	capacity;
}				t_vector;

# define VECTOR_GET(vec, type, index) ((type)vec->data[index])

t_vector		*vector_create(void);
void			vector_resize(t_vector *vector, size_t size);
void			vector_free(t_vector *vector);
void			vector_add(t_vector *vector, void *item);
void			vector_set(t_vector *vector, size_t index, void *item);
void			*vector_get(t_vector *vector, size_t index);
void			*vector_remove(t_vector *vector, size_t index);

#endif
