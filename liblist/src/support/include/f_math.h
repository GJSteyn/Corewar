/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_math.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:53:54 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/28 13:25:51 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_MATH_H
# define F_MATH_H

# define MIN(n1, n2)    (n1 < n2) ? n1 : n2
# define MAX(n1, n2)    (n1 > n2) ? n1 : n2
# define CLAMP(n, min, max)	(n < min ? min : (n > max ? max : n))
# define LERP(n1, n2, perc)	(n1 + ((n2 - n1) * perc))

long long	f_abs(long long nbr);
#endif
