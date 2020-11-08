/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gordey <gordey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:19:26 by gordey            #+#    #+#             */
/*   Updated: 2020/11/08 17:06:54 by gordey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_coord		coneNormal(t_coord rotation, t_objectinfo near, float angle,
		t_coord direct)
{
	t_coord	normal;
	float	k;
	float	m;

	k = tanf(0.5f * (angle * M_PI / 180.0f));
	m = dot(direct, rotation) * near.t + dot(near.st_cent, rotation);
	k = (k * k + 1.0f) * m;
	normal = vectSub(near.center, near.point);
	normal = vectSub(vectMult(rotation, k), normal);
	return (normal);
}

t_coord		cylinNormal(t_coord rotation, t_objectinfo near, t_coord direct)
{
	float	m;
	t_coord	normal;

	m = dot(direct, rotation) * near.t + dot(near.st_cent, rotation);
	normal = vectSub(near.center, near.point);
	normal = vectSub(vectMult(rotation, m), normal);
	return (normal);
}

t_coord		planeNormal(t_coord plane_direct, t_coord cam_direct)
{
	t_coord	normal;

	normal = plane_direct;
	if (dot(cam_direct, normal) > 0.0f)
		normal = vectReverse(normal);
	return (normal);
}

t_coord		objectNormal(t_scene objs, t_objectinfo near)
{
	t_coord		normal;

	if (near.type == SPH)
		normal = vectSub(near.center, near.point);
	else if (near.type == CYLINDER)
		normal = cylinNormal(objs.cyln_objs[near.index].direction, near,
			objs.camera.direct);
	else if (near.type == CONE)
		normal = coneNormal(objs.cone_objs[near.index].direction, near,
			objs.cone_objs[near.index].angle, objs.camera.direct);
	else
		normal = planeNormal(objs.plane_objs[near.index].direction,
			objs.camera.direct);
	return (vectNormal(normal));
}
