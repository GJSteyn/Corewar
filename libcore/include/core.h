/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:29:36 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/29 12:40:49 by kmarchan         ###   ########.fr       */
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

#endif