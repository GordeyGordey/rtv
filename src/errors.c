/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gordey <gordey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:18:35 by gordey            #+#    #+#             */
/*   Updated: 2020/11/08 16:45:29 by gordey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		exitError(char *text)
{
	ft_putstr(text);
	exit(0);
}

void	exitFree(char *text, int code, t_data *data)
{
	ft_putstr(text);
	allFree(data);
	exit(code);
}

void			allFree(t_data *data)
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
