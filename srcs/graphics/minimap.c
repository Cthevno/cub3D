/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 20:53:48 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 12:23:12 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	fill_block(t_game *game, int x, int y, int color)
{
	int	i_max;
	int	j_max;
	int	i;
	int	j;

	i_max = MINIMAP_OFFSET + (x + 1) * (MINIMAP_BLOCK_SIZE
			/ game->map->map_width);
	j_max = MINIMAP_OFFSET + (y + 1) * (MINIMAP_BLOCK_SIZE
			/ game->map->map_height);
	i = MINIMAP_OFFSET + x * (MINIMAP_BLOCK_SIZE / game->map->map_width);
	while (i < i_max)
	{
		j = MINIMAP_OFFSET + y * (MINIMAP_BLOCK_SIZE / game->map->map_height);
		while (j < j_max)
		{
			my_mlx_pixel_put(game->mlx, j, i, color);
			j++;
		}
		i++;
	}
}

void	minimap(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->map_width)
	{
		y = 0;
		while (y < game->map->map_height)
		{
			if (game->map->map[x][y] == 1 || game->map->map[x][y] == 3)
				fill_block(game, x, y, 0x000000);
			else if (game->map->map[x][y] == 2 || game->map->map[x][y] == -1)
				fill_block(game, x, y, 0x00FFFF);
			else
				fill_block(game, x, y, 0xFFFFFF);
			y++;
		}
		x++;
	}
	fill_block(game, (int)game->player->x, (int)game->player->y, 0xFF0000);
}
