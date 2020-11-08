/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gordey <gordey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:19:46 by gordey            #+#    #+#             */
/*   Updated: 2020/11/08 17:11:46 by gordey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				close_window(t_data *data)
{
	allFree(data);
	exit(0);
}

int				buttons_press(int key, t_data *data)
{
	if (key == ESC)
		close_window(data);
	return (0);
}

t_color		getColor(t_scene objs, int type, int index)
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

int			getSpecul(t_scene objs, int type, int index)
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

t_coord		getDirection(t_vector camera, int x, int y)
{
	t_coord		direction;
	t_coord		point;

	point = (t_coord){x - (WIN_WID / 2), (WIN_HIG / 2) - y, WIN_DIST};
	point = vecRotation(point, camera.roter);
	direction = vectNormal(vectSub(camera.point, point));
	return (direction);
}
