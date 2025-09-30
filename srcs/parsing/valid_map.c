/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:38:55 by ctheveno          #+#    #+#             */
/*   Updated: 2025/09/16 12:06:36 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parsing.h"
#include "libft.h"

static int	start_direction(t_map_path *map)
{
	int	x;
	int	y;
	int	direction_player;

	direction_player = 0;
	x = 0;
	while (map->map[x])
	{
		y = 0;
		while (map->map[x][y])
		{
			if (is_direction_player(map->map[x][y]))
				direction_player++;
			y++;
		}
		x++;
	}
	if (direction_player == 0 || direction_player > 1)
		return (0);
	return (1);
}

static int	check_corners(char **m, int *x, int *y)
{
	if (m[*x -1][*y +1] != '1' && m[*x -1][*y +1] != m[*x][*y])
		return (0);
	if (m[*x -1][*y -1] != '1' && m[*x -1][*y -1] != m[*x][*y])
		return (0);
	if (m[*x +1][*y +1] != '1' && m[*x +1][*y +1] != m[*x][*y])
		return (0);
	if (m[*x +1][*y -1] != '1' && m[*x +1][*y -1] != m[*x][*y])
		return (0);
	return (1);
}

static int	all_corners_closed(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (is_direction_player(map[x][y]))
			{
				if (!check_corners(map, &x, &y))
				{
					return (0);
				}
			}
			y++;
		}
		x++;
	}
	return (1);
}

static int	closed_map(t_map_path *map)
{
	char	**map_copy;

	map_copy = ft_copy_doble_tab(map->map);
	if (!map_copy)
		return (0);
	if (!flood_map(map_copy))
	{
		ft_free_doble_tab(map_copy);
		return (0);
	}
	if (!all_corners_closed(map_copy))
	{
		ft_free_doble_tab(map_copy);
		return (0);
	}
	ft_free_doble_tab(map_copy);
	return (1);
}

int	map_is_valid(t_map_path *map)
{
	if (!start_direction(map))
		return (0);
	if (!closed_map(map))
		return (0);
	if (map->ceiling_color == -1 || map->floor_color == -1)
		return (0);
	if (map->path_texture_east == NULL)
		return (0);
	if (map->path_texture_north == NULL)
		return (0);
	if (map->path_texture_south == NULL)
		return (0);
	if (map->path_texture_west == NULL)
		return (0);
	return (1);
}
