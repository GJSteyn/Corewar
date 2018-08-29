/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_little_to_big_endian.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:22:12 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/29 18:05:50 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	f_little_to_big_endian(int little, char big[4])
{
	big[0] = ((unsigned char*)&little)[3];
	big[1] = ((unsigned char*)&little)[2];
	big[2] = ((unsigned char*)&little)[1];
	big[3] = ((unsigned char*)&little)[0];
}
