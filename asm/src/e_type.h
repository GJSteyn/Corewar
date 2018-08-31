/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_type.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:57:40 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/31 08:50:13 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_TYPE_H
# define E_TYPE_H

enum	e_op
{
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
	op_fork, //conflicts with function fork
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
	label_def, //conflicts with type label
	op,
	arg,
	label_arg, //changed for consistancy
	number,
	eol
};

enum	e_arg_code
{
	direct,
	label,
	reg
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
