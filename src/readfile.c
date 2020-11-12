/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:17:55 by gordey            #+#    #+#             */
/*   Updated: 2020/11/11 15:22:49 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		oneline(t_data *data, t_scene *objects, char *line)
{
	char		**arr;

	if (!(arr = ft_strsplit(line, '\t')))
		exit_free("Malloc error\n", 1, data);
	if (ft_arrlen(arr) > 0)
	{
		if (!ft_strcmp(arr[0], "sphere"))
			sphere(data, objects, arr);
		else if (!ft_strcmp(arr[0], "cylinder"))
			cylinder(data, objects, arr);
		else if (!ft_strcmp(arr[0], "cone"))
			cone(data, objects, arr);
		else if (!ft_strcmp(arr[0], "plane"))
			plane(data, objects, arr);
		else if (!ft_strcmp(arr[0], "camera"))
			camera(objects, arr);
		else if (!ft_strcmp(arr[0], "light"))
			if (!ft_strcmp(arr[1], "AMBIENT") || !ft_strcmp(arr[1], "POINT")
				|| !ft_strcmp(arr[1], "DIRECTIONAL"))
				light(data, objects, arr);
		ft_safe_free_arr(arr);
	}
}

void		read_scene(t_data *data, char *name)
{
	int			fd;
	char		*line;

	fd = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		exit_free("Error: file doesn't exist\n", 1, data);
	if (fd == 0 || read(fd, NULL, 0) == -1)
		exit_free("Error: can't read file\n", 1, data);
	while (get_next_line(fd, &line))
	{
		if (line[0] != '@' && ft_strlen(line) > 10)
			oneline(data, data->p_object, line);
		free(line);
	}
	close(fd);
}

void		file_extension(char *param_name)
{
	int		i;
	char	*str;

	i = 0;
	if (*param_name)
	{
		str = param_name;
		i = ft_strlen(str) - 1;
		if (!(str[i] && str[i - 3] == '.' && str[i - 2] == 'r'
			&& str[i - 1] == 't' && str[i] == 'v'))
			exit_error("Invalid file extension\n Valid example: " "name.rtv\n");
	}
	else
		exit_error("No file\n");
}
