/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setdefault.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:29:26 by wendell           #+#    #+#             */
/*   Updated: 2020/11/11 15:29:29 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		object_null(t_scene *objs)
{
	objs->light_srcs = NULL;
	objs->plane_objs = NULL;
	objs->sph_objs = NULL;
	objs->cone_objs = NULL;
	objs->cyln_objs = NULL;
}

void		set_default(t_scene *objs)
{
	objs->camera.point.x = DEFAULT_CAMERA;
	objs->camera.point.y = DEFAULT_CAMERA;
	objs->camera.point.z = DEFAULT_CAMERA;
	objs->light_srcs[0].pos_or_dir.x = DEFAULT_LIGHT;
	objs->light_srcs[0].pos_or_dir.y = DEFAULT_LIGHT;
	objs->light_srcs[0].pos_or_dir.z = DEFAULT_LIGHT;
	objs->light_srcs[0].type = AMBIENT;
	objs->light_srcs[0].intensity = DEFAULT_INTENSIVITY;
}

void		struct_preset(t_scene *objects)
{
	objects->num_sphs = 0;
	objects->num_cylns = 0;
	objects->num_cons = 0;
	objects->num_plans = 0;
	objects->num_l_src = 0;
}
