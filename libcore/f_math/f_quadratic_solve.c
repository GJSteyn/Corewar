/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_quadratic_solve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:42:02 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 11:57:41 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int	f_quadratic_solve(double a, double b, double c, double answer[2])
{
	double	discriminant;

	discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant < 0)
		return (0);
	discriminant = sqrt(discriminant);
	answer[0] = (-b - discriminant) / (2.0 * a);
	answer[1] = (-b + discriminant) / (2.0 * a);
	if (discriminant == 0)
		return (1);
	return (2);
}
