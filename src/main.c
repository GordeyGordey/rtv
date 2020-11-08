/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gordey <gordey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 14:16:02 by gordey            #+#    #+#             */
/*   Updated: 2020/11/08 16:45:29 by gordey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		fileExtension(av[1]);
		if (!(data = (t_data*)malloc(sizeof(t_data))))
			exitFree("Malloc error\n", 1, data);
		if (!(assignment(data, av[1])))
			exitFree("Error\n", 1, data);
		readScene(data, av[1]);
		grafic(data, data->mlx);
		allFree(data);
	}
	else
		return (exitError("No file or too many fieles\n"));
	return (0);
}
