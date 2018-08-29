/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:51:12 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 10:49:53 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdlib.h>
# include <stddef.h>

# include "op.h"
# include "e_type.h"
# include "s_token.h"
# include "list.h"

typedef char			t_bin[CHAMP_MAX_SIZE];
typedef struct s_list	t_token_list;
typedef struct s_token	t_token;

# define DEQUE_TOKEN(list) ((t_token*)list_pop(list, 0))

size_t (*g_op_func[17])(t_token_list*, t_bin, size_t);

size_t	parse_live(t_token_list *token_list, t_bin bin, size_t offset);

#endif