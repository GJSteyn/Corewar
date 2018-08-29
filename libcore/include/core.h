/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:29:36 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/29 18:03:09 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_LIB_H
# define CORE_LIB_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "../../liblist/include/list.h"

size_t					f_strlen(const char *s);
void					*f_memalloc(size_t size);
void					f_bzero(void *s, size_t n);
int						f_isspace(char c);
int						f_isdigit(int c);
int						f_big_to_little_endian(char big[4]);
void					f_little_to_big_endian(int little, char big[4]);
long					f_atol(char *nbr, int *error);

#endif