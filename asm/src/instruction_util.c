/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 19:41:29 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/05 05:21:58 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_instruction.h"
#include <stddef.h>
#include <stdlib.h>

void		instruction_destroy(void *instruction)
{
	free(instruction);
}
