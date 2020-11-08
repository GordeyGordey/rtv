/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gordey <gordey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:19:03 by gordey            #+#    #+#             */
/*   Updated: 2020/11/06 13:19:05 by gordey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_coord		vectReverse(t_coord vector)
{
	if (vector.x != 0.00)
		vector.x = -vector.x;
	if (vector.y != 0.00)
		vector.y = -vector.y;
	if (vector.z != 0.00)
		vector.z = -vector.z;
	return (vector);
}

t_coord		vectSub(t_coord begin_point, t_coord end_point)
{
	t_coord		rez_point;

	rez_point.x = end_point.x - begin_point.x;
	rez_point.y = end_point.y - begin_point.y;
	rez_point.z = end_point.z - begin_point.z;
	return (rez_point);
}

double		dot(t_coord vec_1, t_coord vec_2)
{
	return ((vec_1.x * vec_2.x + vec_1.y * vec_2.y + vec_1.z * vec_2.z));
}

t_coord		vectSum(t_coord vec_1, t_coord vec_2)
{
	t_coord		point;

	point.x = vec_1.x + vec_2.x;
	point.y = vec_1.y + vec_2.y;
	point.z = vec_1.z + vec_2.z;
	return (point);
}

t_coord		vectMult(t_coord vector, double mult)
{
	vector.x *= mult;
	vector.y *= mult;
	vector.z *= mult;
	return (vector);
}
