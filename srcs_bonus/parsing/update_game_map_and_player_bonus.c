/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game_map_and_player_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:22:31 by ctheveno          #+#    #+#             */
/*   Updated: 2025/09/22 10:35:40 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf_fd_buffer/header/ft_printf.h"
#include <stdio.h>
#include "./parsing_bonus.h"
#include <limits.h>
#include <fcntl.h>
#include "./s_player.h"
#include "./s_map.h"
#include "s_ray.h"
#include "main.h"
#include "params.h"

void	update_dir(char c, t_player *player)
{
	if (c == 'N')
	{
		player->angle = PI;
		player->dx = cos(player->angle);
		player->dy = sin(player->angle);
	}
	else if (c == 'S')
	{
		player->angle = 0;
		player->dx = cos(player->angle);
		player->dy = sin(player->angle);
	}
	else if (c == 'E')
	{
		player->angle = PI / 2;
		player->dx = cos(player->angle);
		player->dy = sin(player->angle);
	}
	else if (c == 'W')
	{
		player->angle = PI / -2;
		player->dx = cos(player->angle);
		player->dy = sin(player->angle);
	}
}

void	update_player(char **map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player(map[i][j]))
			{
				player->x = i + 0.5;
				player->y = j + 0.5;
				update_dir(map[i][j], player);
			}
			j++;
		}
		i++;
	}
}

static int	updated_game(t_game *game)
{
	if (game->map->map_width == 0 || game->map->map_height == 0
		|| game->player->x == 0.0)
	{
		free_array(game->map->map, game->map->map_height);
		free_array(game->map->texture_east, TEXTURE_SIZE);
		free_array(game->map->texture_north, TEXTURE_SIZE);
		free_array(game->map->texture_south, TEXTURE_SIZE);
		free_array(game->map->texture_west, TEXTURE_SIZE);
		return (0);
	}
	if (update_game_textures_bonus(game) != 0)
	{
		free_array(game->map->map, game->map->map_height);
		free_array(game->map->texture_east, TEXTURE_SIZE);
		free_array(game->map->texture_north, TEXTURE_SIZE);
		free_array(game->map->texture_south, TEXTURE_SIZE);
		free_array(game->map->texture_west, TEXTURE_SIZE);
		return (0);
	}
	return (1);
}

int	update_pixels_array(t_map_path *map_paths, t_game *game)
{
	if (store_pixels_from_xpm(map_paths->path_texture_east,
			&game->map->texture_east, game->mlx->mlx_ptr) != 0)
		return (1);
	if (store_pixels_from_xpm(map_paths->path_texture_north,
			&game->map->texture_north, game->mlx->mlx_ptr) != 0)
	{
		free_array(game->map->texture_east, TEXTURE_SIZE);
		return (1);
	}
	if (store_pixels_from_xpm(map_paths->path_texture_south,
			&game->map->texture_south, game->mlx->mlx_ptr) != 0)
	{
		free_array(game->map->texture_east, TEXTURE_SIZE);
		free_array(game->map->texture_north, TEXTURE_SIZE);
		return (1);
	}
	if (store_pixels_from_xpm(map_paths->path_texture_west,
			&game->map->texture_west, game->mlx->mlx_ptr) != 0)
	{
		free_array(game->map->texture_east, TEXTURE_SIZE);
		free_array(game->map->texture_north, TEXTURE_SIZE);
		free_array(game->map->texture_south, TEXTURE_SIZE);
		return (1);
	}
	return (0);
}

int	update_game_map_and_player(t_map_path *map_paths, t_game *game)
{
	game->map->ceiling_color = map_paths->ceiling_color;
	game->map->floor_color = map_paths->floor_color;
	game->map->map_height = ft_map_height(map_paths->map);
	game->map->map_width = ft_map_width(map_paths->map);
	game->map->map = map_char_to_int(map_paths->map,
			game->map->map_height, game->map->map_width);
	if (!game->map->map)
		return (1);
	if (update_pixels_array(map_paths, game) != 0)
	{
		free_array(game->map->map, game->map->map_height);
		return (1);
	}
	update_player(map_paths->map, game->player);
	if (!updated_game(game))
		return (1);
	return (0);
}
