/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quater_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gordey <gordey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:19:12 by gordey            #+#    #+#             */
/*   Updated: 2020/11/08 17:02:27 by gordey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			quatNormal(t_quat *q)
{
	double	quat_len;

	quat_len = sqrt(q->w * q->w
	+ q->vec.x * q->vec.x + q->vec.y * q->vec.y + q->vec.z * q->vec.z);
	q->w /= quat_len;
	q->vec.x /= quat_len;
	q->vec.y /= quat_len;
	q->vec.z /= quat_len;
}

t_quat			quatMol(t_quat a, t_quat b)
{
	t_quat	res;

	res.w = a.w * b.w -
	(a.vec.x * b.vec.x + a.vec.y * b.vec.y + a.vec.z * b.vec.z);
	res.vec.x = a.w * b.vec.x + b.w * a.vec.x +
							a.vec.y * b.vec.z - b.vec.y * a.vec.z;
	res.vec.y = a.w * b.vec.y + b.w * a.vec.y +
							a.vec.z * b.vec.x - b.vec.z * a.vec.x;
	res.vec.z = a.w * b.vec.z + b.w * a.vec.z +
							a.vec.x * b.vec.y - b.vec.x * a.vec.y;
	return (res);
}

t_coord			vecRotation(t_coord vector, t_quat rotor)
{
	t_quat	tmp;

	tmp = quatMol(rotor, (t_quat){0.0, vector});
	rotor.vec = vectReverse(rotor.vec);
	quatNormal(&rotor);
	tmp = quatMol(tmp, rotor);
	vector.x = tmp.vec.x;
	vector.y = tmp.vec.y;
	vector.z = tmp.vec.z;
	return (vector);
}

static t_quat	rot(t_quat q, double angle)
{
	t_quat	axis;
	double	a;

	a = angle * M_PI / 360.0;
	axis.w = q.w * cos(a);
	axis.vec.x = q.vec.x * sin(a);
	axis.vec.y = q.vec.y * sin(a);
	axis.vec.z = q.vec.z * sin(a);
	return (axis);
}

t_quat			quatRoter(t_vector camera)
{
	t_quat	roter;
	t_quat	axis_x;
	t_quat	axis_y;
	t_quat	axis_z;

	roter = (t_quat){1, (t_coord){0, 0, 0}};
	axis_x = rot((t_quat){1, (t_coord){1, 0, 0}}, camera.angles.x);
	axis_y = rot((t_quat){1, (t_coord){0, 1, 0}}, camera.angles.y);
	axis_z = rot((t_quat){1, (t_coord){0, 0, 1}}, camera.angles.z);
	roter = quatMol(roter, axis_x);
	roter = quatMol(roter, axis_y);
	roter = quatMol(roter, axis_z);
	return (roter);
}
