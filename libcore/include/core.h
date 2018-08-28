/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:29:36 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/28 14:35:08 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CORE_LIB_H_
# define _CORE_LIB_H_
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "../../liblist/include/list.h"

size_t					f_strlen(const char *s);
void					*f_memalloc(size_t size);
void					f_bzero(void *s, size_t n);
int						f_isspace(char c);

#endif