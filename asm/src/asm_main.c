/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 10:53:19 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/30 13:06:20 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*no_sp;
	char	*no_com;

	if (argc == 2)
	{
		no_sp = get_line(argv[1]);
		no_com = strip_line(no_sp);
		printf("%s", no_com);
		free(no_com);
		free(no_sp);
	}
	return (1);
}
