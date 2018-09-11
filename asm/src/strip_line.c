/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:50:44 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/11 11:53:51 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		newl_over_space(char *str, char **new, int *i, int *n)
{
	if (str[*i] == '\n' && (*new)[(*n) - 1] == ' ')
		(*n)--;
	(*new)[(*n)++] = str[*i];
}

static void		skip_quote(char *str, char **new, int *i, int *n)
{
	(*new)[(*n)++] = str[(*i)++];
	while (str[*i] != '"' && str[*i] != '\0')
		(*new)[(*n)++] = str[(*i)++];
	(*new)[(*n)++] = str[(*i)++];
}

static char		*strip_space(char *str)
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
			new[n++] = str[i];
		}
		else if (!f_isspace_notnewl(str[i]))
			newl_over_space(str, &new, &i, &n);
		else if (i > 0 && f_isspace_notnewl(str[i]) &&
		!f_isspace(str[i - 1]) && str[i + 1] != '\n')
			new[n++] = ' ';
		i++;
	}
	(f_isspace_notnewl(new[n - 1])) && (new[n - 1] = '\0');
	return (new);
}

static char		*strip_comment(char *str)
{
	char	*new;
	int		i;
	int		n;

	i = 0;
	n = 0;
	new = (char *)f_memalloc(sizeof(char) * (f_strlen(str) + 1));
	while (str[i] != '\0')
	{
		if (str[i] == '"')
			skip_quote(str, &new, &i, &n);
		if (str[i] == COMMENT_CHAR)
		{
			if (str[i - 1] == ' ')
				n--;
			while (str[i] != '\n' && str[i] != '\0')
				i++;
		}
		else if (str[i] != COMMENT_CHAR)
			new[n++] = str[i++];
	}
	if (f_isspace_notnewl(str[n - 1]))
		new[n - 1] = '\0';
	return (new);
}

char			*strip_line(char *line)
{
	char	*n_sp;
	char	*n_com;

	n_sp = strip_space(line);
	n_com = strip_comment(n_sp);
	free(n_sp);
	line = n_com;
	return (n_com);
}
