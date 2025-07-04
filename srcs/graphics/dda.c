/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:18:35 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 12:22:48 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	calculate_dda_vars(t_dda *dda, int i, double ray_dir,
		double player_l)
{
	if (ray_dir < 0)
	{
		dda->step[i] = -1;
		dda->side_d[i] = (player_l - (int)player_l) * dda->delta_d[i];
	}
	else
	{
		dda->step[i] = 1;
		dda->side_d[i] = (1 - (player_l - (int)player_l)) * dda->delta_d[i];
	}
}

static void	init_dda_vars(int x, t_dda *dda, t_game *game)
{
	const double	camera_shift = 2.0 * x * game->camera->width_inv - 1;
	double			ray_dir[2];

	ray_dir[0] = game->player->dir_x + game->camera->plane_x * camera_shift;
	ray_dir[1] = game->player->dir_y + game->camera->plane_y * camera_shift;
	if (ray_dir[0] == 0)
		ray_dir[0] = 0.0001;
	if (ray_dir[1] == 0)
		ray_dir[1] = 0.0001;
	dda->delta_d[0] = fabs(1 / ray_dir[0]);
	dda->delta_d[1] = fabs(1 / ray_dir[1]);
	calculate_dda_vars(dda, 0, ray_dir[0], game->player->x);
	calculate_dda_vars(dda, 1, ray_dir[1], game->player->y);
}

static void	update_dda_vars(t_dda *dda, int *dda_map_cell, t_game *game)
{
	if (dda->dir == 0)
	{
		if (game->map->map[dda_map_cell[0]][dda_map_cell[1]] == 2)
			dda->dir = 4;
		else if (game->map->map[dda_map_cell[0]][dda_map_cell[1]] == 3)
			dda->dir = 6;
		else
			dda->dir += 2 * (dda_map_cell[0] > game->player->x);
		dda->wall_d = dda->side_d[0] - dda->delta_d[0];
	}
	else
	{
		if (game->map->map[dda_map_cell[0]][dda_map_cell[1]] == 2)
			dda->dir = 5;
		else if (game->map->map[dda_map_cell[0]][dda_map_cell[1]] == 3)
			dda->dir = 7;
		else
			dda->dir += 2 * (dda_map_cell[1] > game->player->y);
		dda->wall_d = dda->side_d[1] - dda->delta_d[1];
	}
}

void	dda(int x, t_dda *dda, t_game *game)
{
	int	dda_map_cell[2];

	init_dda_vars(x, dda, game);
	dda_map_cell[0] = (int)game->player->x;
	dda_map_cell[1] = (int)game->player->y;
	while (1)
	{
		if (dda->side_d[0] < dda->side_d[1])
		{
			dda->side_d[0] += dda->delta_d[0];
			dda_map_cell[0] += dda->step[0];
			dda->dir = 0;
		}
		else
		{
			dda->side_d[1] += dda->delta_d[1];
			dda_map_cell[1] += dda->step[1];
			dda->dir = 1;
		}
		if (dda_map_cell[0] < 0 || dda_map_cell[0] >= game->map->map_width
			|| dda_map_cell[1] < 0 || dda_map_cell[1] >= game->map->map_height
			|| game->map->map[dda_map_cell[0]][dda_map_cell[1]] > 0)
			break ;
	}
	update_dda_vars(dda, dda_map_cell, game);
}
