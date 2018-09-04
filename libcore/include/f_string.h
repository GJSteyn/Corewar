/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_string.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:36:59 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/02 19:28:57 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_STRING_H
# define F_STRING_H

# include <stddef.h>

size_t	f_strlen(const char *str);
char	*f_strjoin(char const *s1, char const *s2);
char	*f_strcjoin(char const *s1, char const *s2, char c);
char	*f_strcpy(char *dest, const char *src);
int		f_strcmp(const char *s1, const char *s2);
int		f_strncmp(const char *s1, const char *s2, size_t n);
char	*f_strnew(size_t n);
void	f_strdel(char **as);
char	*f_strdup(const char *s);
size_t	f_strlcat(char *dest, const char *src, size_t size);
size_t	f_strnlen(const char *s, size_t maxlen);
char	*f_strresize(char **old, size_t n);
char	*f_strncpy(char *dest, const char *src, size_t n);
char	*f_strchr(const char *s, int c);
char	*f_strrchr(char *str, char c);
char	*f_strstr(const char *haystack, const char *needle);
long	f_strtol(const char *nptr, char **endptr, int base);
int		f_atoi(const char *nptr);
double	f_atof(const char *s);
char	*f_itoa_base(long long nbr, unsigned int base);
char	*f_utoa_base(unsigned long long unbr, unsigned int base);
void	f_striter(char *s, void (*f)(char *));
char	**f_strsplit(char const *s, char c);
void	f_strarrdel(char **array);
char	*f_strsub(char const *str, unsigned int start, size_t len);
char	*f_strtrim(char const *s);
int		f_isalnum(int c);
int		f_isalpha(int c);
int		f_isupper(int c);
int		f_islower(int c);
int		f_toupper(int c);
int		f_isblank(int c);
int		f_isspace(int c);
int		f_isdigit(int c);
int		f_isdigits(char *s);

#endif
