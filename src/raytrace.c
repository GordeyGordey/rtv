/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gordey <gordey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:10:03 by gordey            #+#    #+#             */
/*   Updated: 2020/11/08 17:02:57 by gordey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	tanPlane(t_raydata *ray, t_plane plane)
{
	double		t;
	double		dot_ov_r;
	double		dot_co_r;

	ray->cent_obj = plane.center;
	ray->st_cent = vectSub(plane.center, ray->point);
	dot_co_r = dot(ray->st_cent, plane.direction);
	dot_ov_r = dot(ray->direction, plane.direction);
	t = (-dot_co_r) / dot_ov_r;
	if ((t > 0.00001 && t < ray->t_max))
	{
		ray->t_near = t;
		return (1);
	}
	return (0);
}

int	tanCone(t_raydata *ray, t_cone cone)
{
	t_quadr_equation	factor;
	double				dot_ov_r;
	double				dot_co_r;
	double				k;

	ray->cent_obj = cone.center;
	ray->st_cent = vectSub(cone.center, ray->point);
	dot_co_r = dot(ray->st_cent, cone.direction);
	dot_ov_r = dot(ray->direction, cone.direction);
	k = tan(0.5 * (cone.angle * M_PI / 180));
	k = k * k + 1.0;
	factor.a = dot(ray->direction, ray->direction) - k * pow(dot_ov_r, 2.0);
	factor.b = 2.0 * (dot(ray->direction, ray->st_cent) - k * dot_co_r * dot_ov_r);
	factor.c = dot(ray->st_cent, ray->st_cent) - k * pow(dot_co_r, 2.0);
	return (quadr_equation(factor, ray));
}

int	tanCylin(t_raydata *ray, t_cylindr cyln)
{
	t_quadr_equation	factor;
	double				dot_ov_r;
	double				dot_co_r;

	ray->cent_obj = cyln.center;
	ray->st_cent = vectSub(cyln.center, ray->point);
	dot_co_r = dot(ray->st_cent, cyln.direction);
	dot_ov_r = dot(ray->direction, cyln.direction);
	factor.a = dot(ray->direction, ray->direction) - pow(dot_ov_r, 2.);
	factor.b = 2. * (dot(ray->direction, ray->st_cent) - dot_co_r * dot_ov_r);
	factor.c = dot(ray->st_cent, ray->st_cent) - pow(dot_co_r, 2.0) - cyln.rad * cyln.rad;
	return (quadr_equation(factor, ray));
}

int	tanSph(t_raydata *ray, t_sph sph)
{
	t_quadr_equation	factor;
	t_coord				center;

	ray->cent_obj = sph.center;
	center = vectSub(sph.center, ray->point);
	factor.a = dot(ray->direction, ray->direction);
	factor.b = 2. * dot(center, ray->direction);
	factor.c = dot(center, center) - sph.rad * sph.rad;
	return (quadr_equation(factor, ray));
}

int	rayTrace(t_scene objs, t_raydata ray, t_objectinfo *near)
{
	int	i;

	i = -1;
	near->t = -1.0;
	while (objs.plane_objs && ++i < objs.num_plans)
		if (tanPlane(&ray, objs.plane_objs[i]))
			fixing_the_near_obj(ray, near, PLANE, i);
	i = -1;
	while (objs.sph_objs && ++i < objs.num_sphs)
		if (tanSph(&ray, objs.sph_objs[i]))
			fixing_the_near_obj(ray, near, SPH, i);
	i = -1;
	while (objs.cyln_objs && ++i < objs.num_cylns)
		if (tanCylin(&ray, objs.cyln_objs[i]))
			fixing_the_near_obj(ray, near, CYLINDER, i);
	i = -1;
	while (objs.cone_objs && ++i < objs.num_cons)
		if (tanCone(&ray, objs.cone_objs[i]))
			fixing_the_near_obj(ray, near, CONE, i);
	if (near->t > -1.0)
		return (1);
	else
		return (0);
}
