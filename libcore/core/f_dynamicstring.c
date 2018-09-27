/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_dynamicstring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:26:27 by gsteyn            #+#    #+#             */
/*   Updated: 2018/09/27 11:47:46 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

char			*f_dynamicstring(char **ori, char *add)
{
	char	*tmp;
	char	*ret;

	tmp = f_strdup(*ori);
	free(*ori);
	ret = f_strjoin(tmp, add);
	free(tmp);
	return (ret);
}
