/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:12:37 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 12:42:06 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	fill_camera(t_game *game)
{
	game->camera->width_inv = 1.0 / W_WIDTH;
	game->camera->plane_x = FOV_PARAM * game->player->dir_y;
	game->camera->plane_y = -FOV_PARAM * game->player->dir_x;
}

static int	init_player(t_game **game)
{
	(*game)->player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!(*game)->player)
	{
		free((*game)->map);
		free(*game);
		return (1);
	}
	return (0);
}

static int	init_camera(t_game **game)
{
	(*game)->camera = (t_camera *)ft_calloc(1, sizeof(t_camera));
	if (!(*game)->camera)
	{
		free((*game)->player);
		free((*game)->map);
		free(*game);
		return (1);
	}
	return (0);
}

int	init_game(t_game **game)
{
	*game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!*game)
		return (1);
	(*game)->sprite_counter = 0;
	ft_bzero((*game)->hooks, sizeof((*game)->hooks));
	(*game)->map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!(*game)->map)
	{
		free(*game);
		return (1);
	}
	if (init_player(game))
		return (1);
	if (init_camera(game))
		return (1);
	if (init_mlx(*game))
	{
		free((*game)->player);
		free((*game)->map);
		free(*game);
		return (1);
	}
	return (0);
}
