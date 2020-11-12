/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:17:45 by gordey            #+#    #+#             */
/*   Updated: 2020/11/11 13:26:53 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	double_tail(char *str)
{
	double	tail;
	int		digit1;
	int		digit2;

	digit1 = 0;
	digit2 = 0;
	while (*str != '.')
		str++;
	if (*(str + 1))
		str++;
	if (*str)
	{
		digit1 = ft_to_digit(*str);
		if (*(str + 1))
			digit2 = ft_to_digit(*(str + 1));
	}
	tail = ((double)digit1 * 0.1) + ((double)digit2 * 0.01);
	return (tail);
}

double			coordinate(char *str)
{
	long long int	left;
	double			right;
	double			sign;
	double			res;

	sign = 1.0;
	if (*str)
	{
		left = ft_atoi(str);
		if ((left == 0 && str[0] == '-') || left < 0)
		{
			sign = -1.0;
			left *= -1;
		}
		if (ft_strchr(str, '.'))
			right = double_tail(str);
		else
			right = 0.0;
		res = left + right;
		res = res > 0 ? res * sign : res;
		return (res);
	}
	return (DEFAULT_COORDINATE);
}

void			position(t_coord *p, char *arr, t_data *data)
{
	char	**coord;
	size_t	len;

	if (arr)
	{
		if (!(coord = ft_strsplit(arr, ' ')))
			exit_free("Malloc error\n", 1, data);
		len = ft_arrlen(coord);
		p->x = (len > 0) ? coordinate(coord[0]) : DEFAULT_COORDINATE;
		p->y = (len > 1) ? coordinate(coord[1]) : DEFAULT_COORDINATE;
		p->z = (len > 2) ? coordinate(coord[2]) : DEFAULT_COORDINATE;
		ft_safe_free_arr(coord);
	}
	else
	{
		p->x = DEFAULT_COORDINATE;
		p->y = DEFAULT_COORDINATE;
		p->z = DEFAULT_COORDINATE;
	}
}
