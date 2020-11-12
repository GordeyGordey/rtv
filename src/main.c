/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 14:16:02 by gordey            #+#    #+#             */
/*   Updated: 2020/11/11 13:26:53 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		file_extension(av[1]);
		if (!(data = (t_data*)malloc(sizeof(t_data))))
			exit_free("Malloc error\n", 1, data);
		if (!(assignment(data, av[1])))
			exit_free("Error\n", 1, data);
		read_scene(data, av[1]);
		grafic(data, data->mlx);
		all_free(data);
	}
	else
		return (exit_error("No file or too many fieles\n"));
	return (0);
}
