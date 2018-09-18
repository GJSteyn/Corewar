/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:21:03 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/18 14:44:45 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_H
# define FLAG_H

# define FLAG_TOTAL		5
# define FLAG			"dsvna"
# define HAS_VALS		"dsv"
# define HAS_VAL(f)		(f_strchr(HAS_VALS, f))
# define GET_FLAG(c)	(f_strchr(FLAG, c) - FLAG)
# define INVALID_FLAG	(-FLAG)
# define SET_FARG(f, n)	(g_env.flag_args[f] = n)
# define GET_FARG(f)	(g_env.flag_args[f])

# define FLAG_MEM_DUMP		0
# define FLAG_DUMP_CYCLE	1
# define FLAG_VERBOSE		2
# define FLAG_NCURSES		3
# define FLAG_AFF			4

# define VERB_LIVES			1
# define VERB_CYCLES		2
# define VERB_OPS			4
# define VERB_DEATHS		8
# define VERB_PC			16

# define SET_FLAG(f)			(g_env.flag | (1 << f))

#endif
