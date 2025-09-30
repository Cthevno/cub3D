/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:12:37 by vblanc            #+#    #+#             */
/*   Updated: 2025/08/21 16:18:59 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	init_map(t_game **game)
{
	(*game)->map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!(*game)->map)
	{
		free(*game);
		return (1);
	}
	return (0);
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

static int	init_ray(t_game **game)
{
	(*game)->ray = (t_ray *)ft_calloc(1, sizeof(t_ray));
	if (!(*game)->ray)
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
	(*game)->sprite_count = 0;
	ft_bzero((*game)->hooks, sizeof((*game)->hooks));
	if (init_map(game))
		return (1);
	if (init_player(game))
		return (1);
	if (init_ray(game))
		return (1);
	if (init_mlx(*game))
	{
		free((*game)->ray);
		free((*game)->player);
		free((*game)->map);
		free(*game);
		return (1);
	}
	return (0);
}
