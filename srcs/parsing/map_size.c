/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:20:41 by ctheveno          #+#    #+#             */
/*   Updated: 2025/09/22 14:45:24 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parsing.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>

int	ft_map_height(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
		i++;
	return (i);
}

int	ft_map_width(char **map)
{
	int	i;
	int	j;
	int	width;
	int	current_width;

	i = 0;
	width = 0;
	if (!map)
		return (0);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		current_width = j;
		if (current_width > width)
			width = current_width;
		i++;
	}
	return (width);
}
