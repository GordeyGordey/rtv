/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:19:26 by gordey            #+#    #+#             */
/*   Updated: 2020/11/11 13:30:37 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_coord		cone_normal(t_coord rotation, t_objectinfo near, float angle,
		t_coord direct)
{
	t_coord	normal;
	float	k;
	float	m;

	k = tanf(0.5f * (angle * M_PI / 180.0f));
	m = dot(direct, rotation) * near.t + dot(near.st_cent, rotation);
	k = (k * k + 1.0f) * m;
	normal = vect_sub(near.center, near.point);
	normal = vect_sub(vect_mult(rotation, k), normal);
	return (normal);
}

t_coord		cylin_normal(t_coord rotation, t_objectinfo near, t_coord direct)
{
	float	m;
	t_coord	normal;

	m = dot(direct, rotation) * near.t + dot(near.st_cent, rotation);
	normal = vect_sub(near.center, near.point);
	normal = vect_sub(vect_mult(rotation, m), normal);
	return (normal);
}

t_coord		plane_normal(t_coord plane_direct, t_coord cam_direct)
{
	t_coord	normal;

	normal = plane_direct;
	if (dot(cam_direct, normal) > 0.0f)
		normal = vect_reverse(normal);
	return (normal);
}

t_coord		object_normal(t_scene objs, t_objectinfo near)
{
	t_coord		normal;

	if (near.type == SPH)
		normal = vect_sub(near.center, near.point);
	else if (near.type == CYLINDER)
		normal = cylin_normal(objs.cyln_objs[near.index].direction, near,
			objs.camera.direct);
	else if (near.type == CONE)
		normal = cone_normal(objs.cone_objs[near.index].direction, near,
			objs.cone_objs[near.index].angle, objs.camera.direct);
	else
		normal = plane_normal(objs.plane_objs[near.index].direction,
			objs.camera.direct);
	return (vect_normal(normal));
}
