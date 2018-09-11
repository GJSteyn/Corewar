/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_type.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:57:40 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/11 12:42:48 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_TYPE_H
# define E_TYPE_H

enum	e_op
{
	blank,
	live,
	ld,
	st,
	add,
	sub,
	and,
	or,
	xor,
	zjmp,
	ldi,
	sti,
	op_fork,
	lld,
	lldi,
	lfork,
	aff
};

enum	e_keyword
{
	name,
	comment
};

enum	e_type
{
	keyword,
	text,
	label_def,
	op,
	arg,
	label_arg,
	number,
	eol,
	separator
};

enum	e_arg_code
{
	arg_blank,
	reg,
	direct,
	label,
	indirect
};

union	u_value
{
	int				number;
	char			*text;
	enum e_keyword	keyword;
	enum e_op		op;
	enum e_arg_code	arg;
};

#endif
