/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:49:09 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/27 10:22:08 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <curses.h>
# include <limits.h>
# include <signal.h>

# include "op.h"
# include "s_op.h"
# include "core.h"
# include "process.h"
# include "op_function.h"
# include "s_env.h"
# include "flag.h"
# include "visualiser.h"


# define PLAYER_POS(nbr, total)	(((MEM_SIZE / total) * (nbr - 1)))

void				handle_args(int argc, char *argv[]);
struct s_process	*load_bot(char *path, int player_no);
void				get_next_op(struct s_process *bot);
void				battle_loop(void);
void				battle_loop_vis(void);
int					kill_process(bool (*kill_check)(void*));
int					set_arg_value(struct s_process *bot,
						int arg_types[MAX_ARGS_NUMBER]);

int					fatal(char *str);
void				print_memory(void);

#endif
