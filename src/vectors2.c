/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:22:04 by wendell           #+#    #+#             */
/*   Updated: 2020/11/11 15:22:13 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		vect_len(t_coord vector)
{
	return (sqrt(vector.x * vector.x + vector.y * vector.y
			+ vector.z * vector.z));
}

t_coord		vect_normal(t_coord vector)
{
	double	vec_len;

	vec_len = vect_len(vector);
	vector.x /= vec_len;
	vector.y /= vec_len;
	vector.z /= vec_len;
	return (vector);
}
