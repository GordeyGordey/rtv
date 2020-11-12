/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadraticequation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:19:19 by gordey            #+#    #+#             */
/*   Updated: 2020/11/11 15:21:55 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	min(double a, double b)
{
	if (a > 0.0f && (a < b || b <= 0.))
		return (a);
	else if (b > 0.0f)
		return (b);
	return (0.0f);
}

double	quadr_equation(t_quadr_equation factor, t_raydata *ray)
{
	double	dis;
	double	t_1;
	double	t_2;
	double	t;

	if (((dis = factor.b * factor.b - (4. * factor.a * factor.c)) >= 0.0))
	{
		t_1 = (-factor.b + sqrt(dis)) / (2. * factor.a);
		t_2 = (-factor.b - sqrt(dis)) / (2. * factor.a);
		t = min(t_1, t_2);
		if (t > 0.0001 && t <= ray->t_max)
			ray->t_near = t;
		else
			return (0);
		return (1);
	}
	return (0);
}
