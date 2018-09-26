/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:21:03 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/26 16:48:51 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_H
# define FLAG_H

# define FLAG_TOTAL			8
# define FLAG				" dscainm"
# define HAS_VALS			"dsn"
# define HAS_VAL(f)			(f_strchr(HAS_VALS, f))
# define GET_FLAG(c)		(f_strchr(FLAG, c) - FLAG)
# define INVALID_FLAG		(-FLAG)
# define SET_FARG(f, n)		(g_env.flag_args[f] = n)
# define GET_FARG(f)		(g_env.flag_args[f])

# define FLAG_MEM_DUMP		1
# define FLAG_DUMP_CYCLE	2
# define FLAG_NCURSES		3
# define FLAG_AFF			4
# define FLAG_NO_INTRO		5
# define FLAG_PL_NO			6
# define FLAG_NO_MUSIC		7

# define SET_FLAG(f)		(g_env.flag |= (1 << f))
# define IS_FLAG_SET(f)		(g_env.flag & (1 << f))

#endif
