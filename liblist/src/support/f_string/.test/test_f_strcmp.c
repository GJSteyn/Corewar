/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_f_strcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 05:24:10 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/28 06:33:28 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_string.h"
#include "f_print.h"

static int	test1(void)
{
	char str1[] = "THIS is a string\0 hidden bits";
	char str2[] = "THIS is a string\0 diffent hiddent bits";

	return (!f_strcmp(str1, str2));
}

static int	test2(void)
{
	char str[] = "This is a string\0 hidden bits";
	char *test[] = {
		"THis is a string\0 diffent hiddent bits",
		"this is a string",
 		"This is a strinG",
		"This is a string+",
		"This is a strin",
		NULL};
	int i = -1;
	
	while (test[i++])
		if (!f_strcmp(str, *test))
			return (0);
	return (1);
}

int		main(void)
{
	int		(*test[])(void) = {
		&test1, 
		&test2, 
		NULL};
	int i  = -1;

	f_print_str("strcmp:");	
	while (test[++i])
		if (test[i]())
			f_print_str(" [PASS]");
		else
			f_print_str(" [FAIL]");
	f_print_str("\n");
	return (0);	
}
