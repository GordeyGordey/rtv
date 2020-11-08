/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gordey <gordey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:18:56 by gordey            #+#    #+#             */
/*   Updated: 2020/11/06 13:18:58 by gordey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		vectLen(t_coord vector)
{
	return (sqrt(vector.x * vector.x + vector.y * vector.y
			+ vector.z * vector.z));
}

t_coord		vectNormal(t_coord vector)
{
	double	vec_len;

	vec_len = vectLen(vector);
	vector.x /= vec_len;
	vector.y /= vec_len;
	vector.z /= vec_len;
	return (vector);
}
