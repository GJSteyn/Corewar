/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_string.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:36:59 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 09:50:45 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_STRING_H
# define F_STRING_H

# include <stddef.h>

char	*f_strcpy(char *dest, const char *src);
size_t	f_strlen(const char *str);
char	*f_strnew(size_t n);
void	f_strdel(char **as);
char	*f_strcjoin(char const *s1, char const *s2, char c);
char	*f_strdup(const char *s);

#endif
