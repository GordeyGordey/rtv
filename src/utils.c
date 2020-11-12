/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:19:46 by gordey            #+#    #+#             */
/*   Updated: 2020/11/11 15:21:32 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			close_window(t_data *data)
{
	all_free(data);
	exit(0);
}

int			buttons_press(int key, t_data *data)
{
	if (key == ESC)
		close_window(data);
	return (0);
}

t_color		get_color(t_scene objs, int type, int index)
{
	if (type == SPH)
		return (objs.sph_objs[index].color);
	else if (type == CYLINDER)
		return (objs.cyln_objs[index].color);
	else if (type == CONE)
		return (objs.cone_objs[index].color);
	else
		return (objs.plane_objs[index].color);
}

int			get_specul(t_scene objs, int type, int index)
{
	if (type == SPH)
		return (objs.sph_objs[index].specular);
	else if (type == CYLINDER)
		return (objs.cyln_objs[index].specular);
	else if (type == CONE)
		return (objs.cone_objs[index].specular);
	else
		return (objs.plane_objs[index].specular);
}

t_coord		get_direction(t_vector camera, int x, int y)
{
	t_coord		direction;
	t_coord		point;

	point = (t_coord){x - (WIN_WID / 2), (WIN_HIG / 2) - y, WIN_DIST};
	point = vec_rotation(point, camera.roter);
	direction = vect_normal(vect_sub(camera.point, point));
	return (direction);
}
