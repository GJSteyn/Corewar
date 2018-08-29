/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:50:44 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/29 13:39:23 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libcore/include/core.h"
#include "../../liblist/include/list.h"

char	*strip_space(char *str)
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
				new[n++] = str[i++];
		}
		while (!f_isspace(str[i]))
			new[n++] = str[i++];
		if (i > 0 && f_isspace(str[i]) && !f_isspace(str[i - 1]))
			new[n++] = ' ';
		i++;
	}
	if (f_isspace(new[n - 1]))
		new[n - 1] = '\0';
	return (new);
}

char	*strip_comment(char *str)
{
	char	*new;
	int		i;

	i = 0;
	while (str[i] != '#' && str[i] != '\0')
		i++;
	new = (char *)f_memalloc(sizeof(char) * i);
	if (f_isspace(str[i - 1]))
		i--;
	while (i--)
		new[i] = str[i];
	return (new);
}

void	strip_line(void **line)
{
	char	*n_sp;
	char	*n_com;

	n_sp = strip_space((char*)(*line));
	n_com = strip_comment(n_sp);

	free(line);
	free(n_sp);
	*line = n_com;
}

#include <stdio.h>

int	main(void)
{
	char *str;
	char *new;
	char *new2;

	str = "    this   is    the \"this is a     description		\"	 string		#this is the comment";
	new = strip_space(str);
	new2 = strip_comment(new);
	
	printf("%s\n", new2);
	free(new);
	free(new2);
	return (0);
}

