/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:05:19 by vblanc            #+#    #+#             */
/*   Updated: 2025/09/19 13:58:25 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_use.h"

void	rotate_camera(double angle, t_game *game)
{
	game->player->angle += angle;
	if (game->player->angle < 0)
		game->player->angle += 2 * PI;
	else if (game->player->angle >= 2 * PI)
		game->player->angle -= 2 * PI;
	game->player->dx = cos(game->player->angle);
	game->player->dy = sin(game->player->angle);
}

static void	move(t_game *game, double forward, double strafe)
{
	double	dx;
	double	dy;

	dx = cos(game->player->angle) * forward - sin(game->player->angle) * strafe;
	dy = sin(game->player->angle) * forward + cos(game->player->angle) * strafe;
	dx = dx / sqrt(dx * dx + dy * dy) * MOVE_SPEED;
	dy = dy / sqrt(dx * dx + dy * dy) * MOVE_SPEED;
	if (game->map->map[(int)(game->player->x + dx
			* MOVE_SPEED)][(int)(game->player->y + dy * MOVE_SPEED)] < 1)
	{
		game->player->x += dx * MOVE_SPEED;
		game->player->y += dy * MOVE_SPEED;
	}
}

void	move_player(int keycode, t_game *game)
{
	double	f;
	double	s;

	f = 0.0;
	s = 0.0;
	if (keycode == W_MAC || keycode == W_LINUX)
		f = 1.0;
	if (keycode == S_MAC || keycode == S_LINUX)
		f = -1.0;
	if (keycode == A_MAC || keycode == A_LINUX)
		s = 1.0;
	if (keycode == D_MAC || keycode == D_LINUX)
		s = -1.0;
	move(game, f, s);
}
