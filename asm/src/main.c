/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 10:53:19 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/30 11:12:45 by kmarchan         ###   ########.fr       */
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
		no_sp = f_get_line(argv[1]);
		no_com = strip_line(no_sp);
		printf("%s", no_com);
		free(no_com);
		free(no_sp);
	}
	return (1);
}
