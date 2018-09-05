/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_math.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:53:54 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/07 11:52:34 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_MATH_H
# define F_MATH_H

# define MIN(n1, n2)    (n1 < n2) ? n1 : n2
# define MAX(n1, n2)    (n1 > n2) ? n1 : n2
# define CLAMP(n, min, max)	(n < min ? min : (n > max ? max : n))
# define LERP(n1, n2, perc)	(n1 + ((n2 - n1) * perc))

long long	f_abs(long long nbr);
long		f_min(long base, long test);
long		f_max(long base, long test);
double		f_quadratic_discriminant(double a, double b, double c);
int			f_quadratic_solve(double a, double b, double c, double answer[2]);
#endif
