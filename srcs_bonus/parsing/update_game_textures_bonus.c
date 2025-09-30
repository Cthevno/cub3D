/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game_textures_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:58:16 by ctheveno          #+#    #+#             */
/*   Updated: 2025/09/16 15:06:19 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_game.h"
#include "params.h"
#include "parsing_bonus.h"

int	update_game_textures_bonus(t_game *game)
{
	if (store_pixels_from_xpm("./assets/textures/Wooden_door.xpm",
			&game->map->texture_door, game->mlx->mlx_ptr) != 0)
		return (1);
	game->map->texture_sprite = (int ***)ft_calloc(2, sizeof(int **));
	if (!game->map->texture_sprite)
	{
		free_array(game->map->texture_door, TEXTURE_SIZE);
		return (1);
	}
	if (store_pixels_from_xpm("./assets/textures/Glass_01.xpm",
			&game->map->texture_sprite[0], game->mlx->mlx_ptr) != 0)
	{
		free_array(game->map->texture_door, TEXTURE_SIZE);
		free(game->map->texture_sprite);
		return (1);
	}
	if (store_pixels_from_xpm("./assets/textures/Glass_02.xpm",
			&game->map->texture_sprite[1], game->mlx->mlx_ptr) != 0)
	{
		free_array(game->map->texture_door, TEXTURE_SIZE);
		free_array(game->map->texture_sprite[0], TEXTURE_SIZE);
		free(game->map->texture_sprite);
		return (1);
	}
	return (0);
}
