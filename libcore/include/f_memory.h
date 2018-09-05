/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_memory.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 16:49:07 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/17 23:50:20 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_MEMORY_H
# define F_MEMORY_H

# include <stddef.h>

void	f_bzero(void *s, size_t n);
void	*f_memalloc(size_t size);
void	*f_memccpy(void *dest, const void *src, int c, size_t n);
void	*f_memchr(const void *s, int c, size_t n);
int		f_memcmp(const void *s1, const void *s2, size_t n);
void	*f_memcpy(void *dest, const void *src, size_t n);
void	f_memdel(void **ap);
void	*f_memmove(void *dest, const void *src, size_t n);
void	*f_memset(void *s, int c, size_t n);
void	*f_rawmemchr(const void *s, int c);
long	*f_ptrdiff(void *start, void *end);
void	f_memrev(void *mem, size_t size);
void	f_swapptr(void **p1, void **p2);

#endif
