/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:34:06 by grinko            #+#    #+#             */
/*   Updated: 2019/09/10 14:50:42 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int		i;
	char	*eat;

	i = 0;
	eat = s;
	if (!s)
		return ;
	while (*eat++)
		i++;
	ft_memset(s, '\0', i);
}