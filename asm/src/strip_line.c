/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:50:44 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/28 14:34:23 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libcore/include/core.h"
#include "../../liblist/include/list.h"

char *strip_space(char *str)
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
		if (f_isspace(str[i]) && !f_isspace(str[i - 1]))
			new[n++] = ' ';
		else
			i++;
	}
	return (new);
}

// t_list	*strip_line(t_list *line)
// {
// 	char	*str;
// 	t_list	*tmp;

// 	tmp = line;
// 	while (tmp)
// 	{
// 		str = strip_space(line);
// 		tmp = tmp->head->next;
// 	}
// 	return (line);
// }


#include <stdio.h>
int	main()
{
	char *str;

	str = "    this       is    the				 string			";
	str = strip_space(str);
	printf("%s\n", str);
}
