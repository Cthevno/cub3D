/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 20:53:48 by vblanc            #+#    #+#             */
/*   Updated: 2025/09/16 14:11:42 by ctheveno         ###   ########.fr       */
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
			/ game->map->map_height);
	j_max = MINIMAP_OFFSET + (y + 1) * (1.5 * MINIMAP_BLOCK_SIZE
			/ game->map->map_width);
	i = MINIMAP_OFFSET + x * (MINIMAP_BLOCK_SIZE / game->map->map_height);
	while (i < i_max)
	{
		j = MINIMAP_OFFSET + y
			* (1.5 * MINIMAP_BLOCK_SIZE / game->map->map_width);
		while (j < j_max)
		{
			my_mlx_pixel_put(game->mlx, i, j, color);
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
	while (x < game->map->map_height)
	{
		y = 0;
		while (y < game->map->map_width)
		{
			if (game->map->map[x][y] == 1 || game->map->map[x][y] == 3)
				fill_block(game, y, x, 0x000000);
			else if (game->map->map[x][y] == 2 || game->map->map[x][y] == -1)
				fill_block(game, y, x, 0x00FFFF);
			else
				fill_block(game, y, x, 0xFFFFFF);
			y++;
		}
		x++;
	}
	fill_block(game, game->player->y, game->player->x, 0xFF0000);
}
