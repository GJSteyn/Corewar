/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:21:03 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/22 16:13:50 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_H
# define FLAG_H

# define FLAG_TOTAL			5
# define FLAG				" dsvnai"
# define HAS_VALS			"dsv"
# define HAS_VAL(f)			(f_strchr(HAS_VALS, f))
# define GET_FLAG(c)		(f_strchr(FLAG, c) - FLAG)
# define INVALID_FLAG		(-FLAG)
# define SET_FARG(f, n)		(g_env.flag_args[f] = n)
# define GET_FARG(f)		(g_env.flag_args[f])

# define FLAG_MEM_DUMP		1
# define FLAG_DUMP_CYCLE	2
# define FLAG_VERBOSE		3
# define FLAG_NCURSES		4
# define FLAG_AFF			5
# define FLAG_NO_INTRO		6

# define SET_FLAG(f)		(g_env.flag |= (1 << f))
# define IS_FLAG_SET(f)		(g_env.flag & (1 << f))

# define VERB_LIVES			(IS_VERB_SET(1))
# define VERB_CYCLES		(IS_VERB_SET(2))
# define VERB_OPS			(IS_VERB_SET(4))
# define VERB_DEATHS		(IS_VERB_SET(8))
# define VERB_PC			(IS_VERB_SET(16))

# define START_VERB(print)	if (VERB_OPS){print}
# define PRINT_PROCESS(op)	(f_printf("P %4d | "op, bot->id))
# define PRINT_OFFSET		(f_printf("       |"))
# define PRINT_ARG(n)		(f_printf(" %d", n))
# define PRINT_ARG0			(f_printf(" %d", bot->args[0]))
# define PRINT_ARG1			(f_printf(" %d", bot->args[1]))
# define PRINT_ARG2			(f_printf(" %d", bot->args[2]))
# define PRINT_REG(r)		(f_printf(" r%d", r))
# define PRINT_ENDL			(f_printf("\n"))
# define PRINT_OK			(f_printf(" OK"));
# define PRINT_FAIL			(f_printf(" FAILED"));

# define IS_VERB_SET(v)		(g_env.flag_args[FLAG_VERBOSE] & v)

#endif
