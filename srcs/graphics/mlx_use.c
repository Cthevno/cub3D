/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_use.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:01:42 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 12:30:12 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_use.h"

static int	keyd_manager(int keycode, t_game *game)
{
	if (keycode == ESC_MAC || keycode == ESC_LINUX)
		clear_game(game);
	if (keycode == W_MAC || keycode == W_LINUX)
		game->hooks[W] = true;
	else if (keycode == S_MAC || keycode == S_LINUX)
		game->hooks[S] = true;
	else if (keycode == A_MAC || keycode == A_LINUX)
		game->hooks[A] = true;
	else if (keycode == D_MAC || keycode == D_LINUX)
		game->hooks[D] = true;
	else if (keycode == LEFT_MAC || keycode == LEFT_LINUX)
		game->hooks[LEFT] = true;
	else if (keycode == RIGHT_MAC || keycode == RIGHT_LINUX)
		game->hooks[RIGHT] = true;
	else if (keycode == SPACE_MAC || keycode == SPACE_LINUX)
		open_door(game);
	return (0);
}

static int	keyu_manager(int keycode, t_game *game)
{
	if (keycode == W_MAC || keycode == W_LINUX)
		game->hooks[W] = false;
	else if (keycode == S_MAC || keycode == S_LINUX)
		game->hooks[S] = false;
	else if (keycode == A_MAC || keycode == A_LINUX)
		game->hooks[A] = false;
	else if (keycode == D_MAC || keycode == D_LINUX)
		game->hooks[D] = false;
	else if (keycode == LEFT_MAC || keycode == LEFT_LINUX)
		game->hooks[LEFT] = false;
	else if (keycode == RIGHT_MAC || keycode == RIGHT_LINUX)
		game->hooks[RIGHT] = false;
	else if (keycode == SPACE_MAC || keycode == SPACE_LINUX)
		game->hooks[SPACE] = false;
	return (0);
}

int	init_mlx(t_game *game)
{
	game->mlx = (t_mlx *)ft_calloc(1, sizeof(t_mlx));
	if (!game->mlx)
		return (1);
	game->mlx->mlx_ptr = mlx_init();
	if (!game->mlx->mlx_ptr)
	{
		free(game->mlx);
		return (1);
	}
	game->mlx->mlx_win = mlx_new_window(game->mlx->mlx_ptr, W_WIDTH, W_HEIGHT,
			"cub3D");
	game->mlx->img = mlx_new_image(game->mlx->mlx_ptr, W_WIDTH, W_HEIGHT);
	game->mlx->addr = mlx_get_data_addr(game->mlx->img, &game->mlx->bpp,
			&game->mlx->line_length, &game->mlx->endian);
	mlx_hook(game->mlx->mlx_win, ON_KEYDOWN, KeyPressMask, keyd_manager, game);
	mlx_hook(game->mlx->mlx_win, ON_KEYUP, KeyReleaseMask, keyu_manager, game);
	mlx_hook(game->mlx->mlx_win, ON_DESTROY, 0, clear_game, game);
	mlx_mouse_move(game->mlx->mlx_ptr, game->mlx->mlx_win, W_WIDTH / 2, W_HEIGHT
		/ 2);
	mlx_mouse_hide(game->mlx->mlx_ptr, game->mlx->mlx_win);
	mlx_set_font(game->mlx->mlx_ptr, game->mlx->mlx_win, "9x15bold");
	return (0);
}

int	clear_game(t_game *game)
{
	mlx_destroy_image(game->mlx->mlx_ptr, game->mlx->img);
	mlx_destroy_window(game->mlx->mlx_ptr, game->mlx->mlx_win);
	mlx_destroy_display(game->mlx->mlx_ptr);
	free(game->mlx->mlx_ptr);
	free(game->mlx);
	free_array(game->map->map, game->map->map_width);
	free_array(game->map->texture_north, TEXTURE_SIZE);
	free_array(game->map->texture_south, TEXTURE_SIZE);
	free_array(game->map->texture_east, TEXTURE_SIZE);
	free_array(game->map->texture_west, TEXTURE_SIZE);
	free_array(game->map->texture_door, TEXTURE_SIZE);
	free_array(game->map->texture_sprite[0], TEXTURE_SIZE);
	free_array(game->map->texture_sprite[1], TEXTURE_SIZE);
	free(game->map->texture_sprite);
	free(game->map);
	free(game->player);
	free(game->camera);
	free(game);
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
}
