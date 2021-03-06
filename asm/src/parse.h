/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:51:12 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/17 12:30:00 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdlib.h>
# include <stddef.h>

# include "op.h"
# include "e_type.h"
# include "s_token.h"
# include "s_label.h"
# include "list.h"
# include "core.h"

# define MAGIC_SIZE 4
# define HEADER_SIZE MAGIC_SIZE + PROG_NAME_LENGTH + COMMENT_LENGTH + 4

typedef char				t_bin[CHAMP_MAX_SIZE];
typedef struct s_list		t_token_list;
typedef struct s_token		t_token;
typedef struct s_list		t_label_list;
typedef struct s_list		t_instr_list;
typedef struct s_label		t_label;
typedef struct s_dref_label	t_dref_label;

# define DEQUE_TOKEN(list)	((t_token*)list_pop(list, 0))
# define PEEK_TOKEN(list)	((t_token*)list_get(list, 0))
# define DEQUE_DREF(list)	((t_dref_label*)list_pop(list, 0))

size_t			(*g_op_func[17])(t_token_list*, t_bin, size_t);

size_t			parse_live(t_token_list *token_list, t_bin bin, size_t offset);

# define LABEL_LIST_INIT	(1)
# define LABEL_LIST_GET	(0)
# define LABEL_LIST_CLEAR	(-1)

t_label_list	*gdref_list(int mode);
void			add_gdref(char *name, int *value, size_t offset);
t_label_list	*glabel_list(int mode);
void			add_glabel(char *name, size_t offset);

t_header		*parse_header(t_token_list *token_list);

void			parse_set_labels(void);

void			instruction_destroy(void *instruction);
void			parse_error(char *err_str, size_t line);
size_t			goffset(size_t add);
t_instr_list	*parse_instructions(t_token_list *token_list, t_header *head);

char			*g_types[9];
char			*g_ops[17];
char			*g_args[5];

void			print_instructions(t_header *header, t_instr_list *instr_list);
void			print_tokens(t_token_list *token_list);
void			print_verbose(t_header *header, t_token_list *token_list,
												t_instr_list *instr_list);

#endif
