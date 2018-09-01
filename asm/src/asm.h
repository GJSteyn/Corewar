/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 10:58:44 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/01 12:49:34 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

# include "core.h"
# include "op.h"
# include "list.h"

# include "parse.h"

char	*strip_line(char *line);
char	*get_line(char *path);
t_list	*lex(char *clean_line);

#endif
