/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:50:58 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/11 13:38:45 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEX_H
# define LEX_H

# include <stdbool.h>
# include "list.h"
# include "s_token.h"

typedef struct s_token			t_token;

void		destroy_token(void *token);
bool		f_strmatch(const char *str, char *match);
int			f_intlen(long n);
bool		is_op(char *str);
bool		is_reg(char *str);
bool		is_label(char *str);

void		add_newline(t_list *list, char **str, size_t *line);
void		add_name(t_list *list, char **str, size_t line);
void		add_comment(t_list *list, char **str, size_t line);
void		add_text(t_list *list, char **str, size_t line);
void		add_number(t_list *list, char **str, size_t line);
void		add_label_arg(t_list *list, char **str, size_t line);
void		add_label_def(t_list *list, char **str, size_t line);
void		add_direct(t_list *list, char **str, size_t line);
void		add_indirect(t_list *list, char **str, size_t line);
void		add_separator(t_list *list, char **str, size_t line);
void		add_op(t_list *list, char **str, size_t line);
void		add_reg(t_list *list, char **str, size_t line);
void		skip_line(char **str);

void		lex_error(char *err_str, size_t line);

#endif
