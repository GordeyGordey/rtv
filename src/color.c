/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:48:42 by wendell           #+#    #+#             */
/*   Updated: 2020/11/11 15:10:45 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		colors_sum(t_color v1, t_color v2)
{
	v1.r = ft_check_borders((double)v1.r + (double)v2.r, 0, 255);
	v1.g = ft_check_borders((double)v1.g + (double)v2.g, 0, 255);
	v1.b = ft_check_borders((double)v1.b + (double)v2.b, 0, 255);
	return (v1);
}

t_color		color_scal(t_color color, double mult)
{
	color.r = ft_check_borders((double)color.r * mult, 0, 255);
	color.g = ft_check_borders((double)color.g * mult, 0, 255);
	color.b = ft_check_borders((double)color.b * mult, 0, 255);
	return (color);
}

void		put_color_to_img(int **img_data, int x, int y, t_color color)
{
	(*img_data)[((y * WIN_WID) + x)] = color.r << 16;
	(*img_data)[((y * WIN_WID) + x)] += color.g << 8;
	(*img_data)[((y * WIN_WID) + x)] += color.b;
}

void		color_change(t_color *color, t_color rgb)
{
	color->r = rgb.r;
	color->g = rgb.g;
	color->b = rgb.b;
}

void		color(t_color *color, char *arr)
{
	*color = (t_color){0, 0, 0};
	if (arr)
	{
		if (!ft_strcmp(arr, "red"))
			color_change(color, RED);
		else if (!ft_strcmp(arr, "green"))
			color_change(color, GREEN);
		else if (!ft_strcmp(arr, "blue"))
			color_change(color, BLUE);
		else if (!ft_strcmp(arr, "yellow"))
			color_change(color, YELLOW);
		else if (!ft_strcmp(arr, "white"))
			color_change(color, WHITE);
		else if (!ft_strcmp(arr, "orange"))
			color_change(color, ORANGE);
		else if (!ft_strcmp(arr, "pink"))
			color_change(color, PINK);
		else if (!ft_strcmp(arr, "metal"))
			color_change(color, METAL);
	}
}
