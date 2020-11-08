/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gordey <gordey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:18:43 by gordey            #+#    #+#             */
/*   Updated: 2020/11/06 13:37:04 by gordey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	camera(t_scene *objects, char **arr)
{
	size_t		len;

	len = ft_arrlen(arr);
	if (len > 1)
		position(&objects->camera.point, arr[1], NULL);
	if (len > 2)
		position(&objects->camera.angles, arr[2], NULL);
}
