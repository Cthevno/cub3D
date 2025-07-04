/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:05:19 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 12:31:28 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_use.h"

void	rotate_camera(double angle, t_game *game)
{
	const double	old_dir_x = game->player->dir_x;
	const double	old_dir_y = game->player->dir_y;
	const double	old_plane_x = game->camera->plane_x;
	const double	old_plane_y = game->camera->plane_y;

	game->player->dir_x = old_dir_x * cos(angle) - old_dir_y * sin(angle);
	game->player->dir_y = old_dir_x * sin(angle) + old_dir_y * cos(angle);
	game->camera->plane_x = old_plane_x * cos(angle) - old_plane_y * sin(angle);
	game->camera->plane_y = old_plane_x * sin(angle) + old_plane_y * cos(angle);
}

static bool	is_move_valid(double mode, const double player_loc[2],
		const double move_dir[2], t_game *game)
{
	const int	x_max = player_loc[0] + mode * (move_dir[0] * MOVE_SPEED + 0.1);
	const int	x_min = player_loc[0] + mode * (move_dir[0] * MOVE_SPEED - 0.1);
	const int	y_max = player_loc[1] + mode * (move_dir[1] * MOVE_SPEED + 0.1);
	const int	y_min = player_loc[1] + mode * (move_dir[1] * MOVE_SPEED - 0.1);

	if (game->map->map[x_max][y_min] > 0 || game->map->map[x_max][y_max] > 0
		|| game->map->map[x_min][y_min] > 0 || game->map->map[x_min][y_max] > 0)
		return (false);
	return (true);
}

void	move_player(int keycode, t_game *game)
{
	const double	player_loc[2] = {game->player->x, game->player->y};
	const double	move_dir[2] = {game->player->dir_x, game->player->dir_y};

	if (keycode == W_MAC || keycode == W_LINUX)
	{
		if (!is_move_valid(1.0, player_loc, move_dir, game))
			return ;
		game->player->x += game->player->dir_x * MOVE_SPEED;
		game->player->y += game->player->dir_y * MOVE_SPEED;
	}
	else if (keycode == S_MAC || keycode == S_LINUX)
	{
		if (!is_move_valid(-1.0, player_loc, move_dir, game))
			return ;
		game->player->x -= game->player->dir_x * MOVE_SPEED;
		game->player->y -= game->player->dir_y * MOVE_SPEED;
	}
}

void	move_player_sides(int keycode, t_game *game)
{
	const double	player_loc[2] = {game->player->x, game->player->y};
	const double	mv_dir[2] = {game->camera->plane_x, game->camera->plane_y};

	if (keycode == A_MAC || keycode == A_LINUX)
	{
		if (!is_move_valid(-1.0, player_loc, mv_dir, game))
			return ;
		game->player->x -= game->camera->plane_x * MOVE_SPEED;
		game->player->y -= game->camera->plane_y * MOVE_SPEED;
	}
	else if (keycode == D_MAC || keycode == D_LINUX)
	{
		if (!is_move_valid(1.0, player_loc, mv_dir, game))
			return ;
		game->player->x += game->camera->plane_x * MOVE_SPEED;
		game->player->y += game->camera->plane_y * MOVE_SPEED;
	}
}

void	open_door(t_game *game)
{
	int	x;
	int	y;

	x = (int)game->player->x;
	y = (int)game->player->y;
	if (x + 1 < game->map->map_width && game->map->map[x + 1][y] == 2)
		game->map->map[x + 1][y] = -1;
	else if (x + 1 < game->map->map_width && game->map->map[x + 1][y] == -1)
		game->map->map[x + 1][y] = 2;
	else if (x - 1 >= 0 && game->map->map[x - 1][y] == 2)
		game->map->map[x - 1][y] = -1;
	else if (x - 1 >= 0 && game->map->map[x - 1][y] == -1)
		game->map->map[x - 1][y] = 2;
	else if (y + 1 < game->map->map_height && game->map->map[x][y + 1] == 2)
		game->map->map[x][y + 1] = -1;
	else if (y + 1 < game->map->map_height && game->map->map[x][y + 1] == -1)
		game->map->map[x][y + 1] = 2;
	else if (y - 1 >= 0 && game->map->map[x][y - 1] == 2)
		game->map->map[x][y - 1] = -1;
	else if (y - 1 >= 0 && game->map->map[x][y - 1] == -1)
		game->map->map[x][y - 1] = 2;
}
