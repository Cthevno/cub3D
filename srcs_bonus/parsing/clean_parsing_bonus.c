/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parsing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:30:49 by ctheveno          #+#    #+#             */
/*   Updated: 2025/09/22 15:38:10 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "./parsing_bonus.h"
#include <stdlib.h>

int	clean_line(char *str)
{
	ft_free(&str);
	return (0);
}

void	*clean_map(t_map_path *map)
{
	ft_free(&map->path_texture_east);
	ft_free(&map->path_texture_north);
	ft_free(&map->path_texture_south);
	ft_free(&map->path_texture_west);
	if (map->map != NULL)
		ft_free_doble_tab(map->map);
	free(map);
	return (NULL);
}

void	clear_parsing(t_game *game)
{
	mlx_destroy_image(game->mlx->mlx_ptr, game->mlx->img);
	mlx_destroy_window(game->mlx->mlx_ptr, game->mlx->mlx_win);
	mlx_destroy_display(game->mlx->mlx_ptr);
	free(game->mlx->mlx_ptr);
	free(game->mlx);
	free(game->map);
	free(game->player);
	free(game->ray);
	free(game);
}
