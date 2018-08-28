/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_memory.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 16:49:07 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/28 13:47:41 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_MEMORY_H
# define F_MEMORY_H

# include <stddef.h>
# include <stdlib.h>

void	f_memdel(void **ap);
void	*f_memalloc(size_t size);
void	f_bzero(void *s, size_t n);
void	*f_memcpy(void *dest, const void *src, size_t n);
void	*f_memset(void *s, int c, size_t n);
void	*f_memccpy(void *dest, const void *src, int c, size_t n);

#endif
