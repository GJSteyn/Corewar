/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 08:28:53 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/07 10:34:26 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "f_print.h"

void	f_exit(int code)
{
	exit(code);
}

void	f_eexit(int code, char *s)
{
	f_printf("Error: %s\n", s);
	f_exit(code);
}
