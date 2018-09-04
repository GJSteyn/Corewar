/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_quadratic_discriminant.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:43:54 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 11:56:43 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

double	f_quadratic_discriminant(double a, double b, double c)
{
	return (pow(b, 2) - 4 * a * c);
}
