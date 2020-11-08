/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gordey <gordey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:14:38 by gordey            #+#    #+#             */
/*   Updated: 2020/11/08 16:59:52 by gordey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		objectsmalloc(t_scene *objs, int *num_obj)
{
	if ((num_obj[0] &&
	!(objs->light_srcs = (t_light *)malloc(sizeof(t_light) * (num_obj[0]))))
	|| (num_obj[1] &&
	!(objs->sph_objs = (t_sph *)malloc(sizeof(t_sph) * (num_obj[1]))))
	|| (num_obj[2] &&
	!(objs->cyln_objs = (t_cylindr *)malloc(sizeof(t_cylindr) * (num_obj[2]))))
	|| (num_obj[3] &&
	!(objs->cone_objs = (t_cone *)malloc(sizeof(t_cone) * (num_obj[3]))))
	|| (num_obj[4] &&
	!(objs->plane_objs = (t_plane *)malloc(sizeof(t_plane) * (num_obj[4])))))
		return (0);
	return (1);
}

void			fdValid(int fd, t_data *data)
{
	if (fd < 0)
		exitFree("Error: file doesn't exist\n", 1, data);
	if (fd == 0 || read(fd, NULL, 0) == -1)
		exitFree("Error: can't read file\n", 1, data);
}

static int		*countFigure(char *name, int fd, char *line, int *flags)
{
	fd = open(name, O_RDONLY);
	fdValid(fd, NULL);
	while (get_next_line(fd, &line))
	{
		if (line[0] != '#' && ft_strlen(line) > 10)
		{
			if (!ft_strncmp(line, "light\t", 6))
				flags[0]++;
			else if (!ft_strncmp(line, "sphere\t", 7))
				flags[1]++;
			else if (!ft_strncmp(line, "cylinder\t", 9))
				flags[2]++;
			else if (!ft_strncmp(line, "cone\t", 5))
				flags[3]++;
			else if (!ft_strncmp(line, "plane\t", 6))
				flags[4]++;
			else if (!ft_strncmp(line, "camera\t", 7))
				flags[5]++;
		}
		free(line);
	}
	close(fd);
	// check_cam_and_light(figs);
	if (flags[0] == 0)
		flags[0] = 1;
	if (flags[1] == 0 && flags[2] == 0 && flags[3] == 0 && flags[4] == 0)
		exitError("SCENE ERROR: There is no figures in configuration file!");
	if (flags[5] > 1)
		exitError("SCENE ERROR: In configuration file should be only "
			"1 camera! not less not more!\n");
	return (flags);
}

int				assignment(t_data *data, char *param_name)
{
	t_scene		*objs;
	int			*num_obj;
	int			arr[6];

	ft_izero(arr, 6);
	if (!(objs = (t_scene *)malloc(sizeof(t_scene))))
		return (-1);
	objectNull(objs);
	num_obj = countFigure(param_name, 0, NULL, arr);
	if (!(data->mlx = (t_mlx *)malloc(sizeof(t_mlx))) || !objectsmalloc(objs, num_obj))
		return (-1);
	data->p_object = objs;
	objs->num_l_src = num_obj[0];
	objs->num_sphs = num_obj[1];
	objs->num_cylns = num_obj[2];
	objs->num_cons = num_obj[3];
	objs->num_plans = num_obj[4];
	setDefault(objs);
	return (1);
}
