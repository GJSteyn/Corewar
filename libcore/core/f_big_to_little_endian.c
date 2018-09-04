/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_big_to_little_endian.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:01:36 by pstubbs           #+#    #+#             */
/*   Updated: 2018/09/04 21:54:03 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		f_big_to_little_endian(char big[4])
{
	int	ret;

	((unsigned char*)&ret)[3] = (big)[0];
	((unsigned char*)&ret)[2] = (big)[1];
	((unsigned char*)&ret)[1] = (big)[2];
	((unsigned char*)&ret)[0] = (big)[3];
	return (ret);
}
