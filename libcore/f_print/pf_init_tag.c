/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_init_tag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 22:17:31 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/30 15:34:14 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/s_printf_tag.h"

void	init_tag(t_tag *tag)
{
	tag->spec = 0;
	tag->left_just = false;
	tag->sign = false;
	tag->space = false;
	tag->prefix = false;
	tag->zeropad = false;
	tag->min_width = 0;
	tag->va_width = false;
	tag->p_set = false;
	tag->precision = 0;
	tag->va_prec = false;
	tag->mem_size = 0;
	tag->is_neg = 0;
	tag->space = 0;
	tag->diff = 0;
	tag->mw_set = 0;
}
