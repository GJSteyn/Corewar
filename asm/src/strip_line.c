/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:50:44 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/29 18:55:35 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libcore/include/core.h"
#include "../../liblist/include/list.h"
#include "../../libcore/include/op.h"

#include <stdio.h>

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

static char	*strip_space(char *str)
{
	char	*new;
	int		i;
	int		n;

	i = 0;
	n = 0;
	new = (char *)f_memalloc(sizeof(char) * f_strlen(str));
	while (str[i] != '\0')
	{
		if (str[i] == '"')
		{
			new[n++] = str[i++];
			while (str[i] != '"')
			{
				new[n++] = str[i++];
			}
			new[n++] = str[i++];
		}
		else if (!is_space(str[i]))
			new[n++] = str[i];
		else if (i > 0 && is_space(str[i]) && !f_isspace(str[i - 1])
			new[n++] = ' ';
		i++;
	}
	if (is_space(new[n - 1]))
		new[n - 1] = '\0';
	return (new);
}

static char	*strip_comment(char *str)
{
	char	*new;
	int		i;
	int		n;

	i = 0;
	n = 0;
	new = (char *)f_memalloc(sizeof(char) * f_strlen(str));
	while (str[i] != '\0')
	{
		if (str[i] == COMMENT_CHAR)
		{
			if (str[i - 1] == ' ')
				n--;
			while (str[i] != '\n' && str[i] != '\0')
				i++;
		}
		else if (str[i] != COMMENT_CHAR)
		{
			new[n++] = str[i++];
		}
	}
	if (is_space(str[n - 1]))
		new[n - 1] = '\0';
	return (new);
}

char	*strip_line(char *line)
{
	char	*n_sp;
	char	*n_com;

	n_sp = strip_space(line);
	n_com = strip_comment(n_sp);

	free(n_sp);
	line = n_com;
	return (n_com);
}

// int	main(void)
// {
// 	char *str;
// 	char *new;
// 	int i;

// 	i = 0;
// 	str = "    this   is   \n  the string \"this is a  \n   description		\"	 string  		and 	stuff	#this is the comment\n \
// 	and more stuff. and another #try again \n and more";
// 	new = strip_line((void *)str);

// 	printf("\n%s\n\n\n\n", new);
// 	free(new);
// 	return (0);
// }
