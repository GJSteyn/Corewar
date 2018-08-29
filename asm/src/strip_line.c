/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:50:44 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/29 10:37:35 by kmarchan         ###   ########.fr       */
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

void	strip_line(void **line)
{
	char	*str;
	char	*str2;

	str = strip_space((char*)(*line));
	str2 = strip_comment(str);

	free(line);
	free(str);
	*line = str2;
}


#include <stdio.h>
int	main()
{
	char *str;
	char *new;

	str = "    this       is    the				 string			";
	new = strip_space(str);
	printf("%s\n", new);
}

