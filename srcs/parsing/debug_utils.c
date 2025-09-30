/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:04:09 by ctheveno          #+#    #+#             */
/*   Updated: 2025/09/16 14:34:34 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	printf("----------MAP--------------\n");
	while (map && map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("----------------------------\n");
}

void	print_map_data(t_map_path *map)
{
	printf("N : '%s'\n S : '%s'\n E : '%s'\n W : '%s'\n",
		map->path_texture_north, map->path_texture_south,
		map->path_texture_east, map->path_texture_west);
	printf("C : %d\n F : %d\n", map->ceiling_color, map->floor_color);
	print_map(map->map);
}

void	print_game_map(int **map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			printf("%d", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_texture_array(int **texture)
{
	int	i;
	int	j;

	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			printf("| %d |", texture[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
