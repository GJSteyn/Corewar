/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 10:55:53 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 11:15:47 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

size_t	parse_live(t_token_list token_list, t_bin bin, size_t offset)
{
	t_token *arg;

	bin[offset] = 0x01;
	arg = DEQUE_TOKEN(token_list);

}
