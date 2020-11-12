/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:48:51 by wendell           #+#    #+#             */
/*   Updated: 2020/11/11 14:49:31 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		exit_error(char *text)
{
	ft_putstr(text);
	exit(0);
}

void	exit_free(char *text, int code, t_data *data)
{
	ft_putstr(text);
	all_free(data);
	exit(code);
}

void	all_free(t_data *data)
{
	if (data)
	{
		ft_safe_free(data->mlx);
		ft_safe_free(data->p_object->sph_objs);
		ft_safe_free(data->p_object->cone_objs);
		ft_safe_free(data->p_object->cyln_objs);
		ft_safe_free(data->p_object->plane_objs);
		ft_safe_free(data->p_object->light_srcs);
		ft_safe_free(data->p_object);
		ft_safe_free(data);
	}
}
