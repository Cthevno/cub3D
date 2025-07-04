/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_file_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 22:26:26 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 12:29:38 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	test_fill_map(t_map **map)
{
	int	test_map[8][10] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 0, 0, 1, 0, 0,
			0, 1, 1}, {1, 0, 1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 2, 0, 0, 0, 0,
			0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0,
			1}, {1, 1, 0, 0, 0, 0, 0, 0, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

	// Initialize map dimensions and allocate memory
	(*map)->map_width = 8;
	(*map)->map_height = 10;
	(*map)->map = (int **)ft_calloc((*map)->map_width, sizeof(int *));
	if (!(*map)->map)
	{
		printf("Error allocating memory for map\n");
		return (1);
	}
	for (int i = 0; i < (*map)->map_width; i++)
	{
		(*map)->map[i] = (int *)ft_calloc((*map)->map_height, sizeof(int));
		if (!(*map)->map[i])
		{
			printf("Error allocating memory for map row\n");
			for (int j = 0; j < i; j++)
				free((*map)->map[j]);
			free((*map)->map);
			return (1);
		}
	}
	// Fill with a simple test map
	for (int x = 0; x < (*map)->map_width; x++)
	{
		for (int y = 0; y < (*map)->map_height; y++)
			(*map)->map[x][y] = test_map[x][y];
	}
	(*map)->ceiling_color = 0x00AAFF;
	(*map)->floor_color = 0xA0A0A0;
	return (0);
}

static int	test_fill_texture(int ***texture, int color)
{
	*texture = (int **)ft_calloc(TEXTURE_SIZE, sizeof(int *));
	if (!*texture)
		return (1);
	for (int i = 0; i < TEXTURE_SIZE; i++)
	{
		(*texture)[i] = (int *)ft_calloc(TEXTURE_SIZE, sizeof(int));
		if (!(*texture)[i])
		{
			for (int j = 0; j < i; j++)
				free((*texture)[j]);
			free(*texture);
			return (1);
		}
		for (int j = 0; j < TEXTURE_SIZE; j++)
		{
			if (i == 0 || j == 0 || i == TEXTURE_SIZE - 1 || j == TEXTURE_SIZE
				- 1 || i == j || i == TEXTURE_SIZE - j - 1)
				(*texture)[i][j] = 0x000000;
			else
				(*texture)[i][j] = color;
		}
	}
	return (0);
}

static void	test_fill_player(t_player **player)
{
	(*player)->x = 3.5;
	(*player)->y = 4.5;
	(*player)->dir_x = -1.0;
	(*player)->dir_y = 0.0;
}

int	test_fill_game(t_game *game)
{
	if (test_fill_map(&game->map))
	{
		free(game);
		return (1);
	}
	test_fill_texture(&game->map->texture_north, 0xFF0000);
	test_fill_texture(&game->map->texture_south, 0x0000FF);
	test_fill_texture(&game->map->texture_east, 0xFFFFFF);
	test_fill_texture(&game->map->texture_west, 0x00FF00);
	test_fill_texture(&game->map->texture_door, 0xFFFF00);
	game->map->texture_sprite = (int ***)ft_calloc(2, sizeof(int **));
	if (!game->map->texture_sprite)
		return (1);
	test_fill_texture(&game->map->texture_sprite[0], 0xc100ff);
	test_fill_texture(&game->map->texture_sprite[1], 0xff008f);
	test_fill_player(&game->player);
	return (0);
}
