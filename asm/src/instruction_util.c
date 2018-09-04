/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 19:41:29 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/04 19:42:01 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_instruction.h"

void		instruction_destroy(struct s_instruction *instruction)
{
	free(instruction);
}
