/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:21:14 by vblanc            #+#    #+#             */
/*   Updated: 2025/08/21 16:05:51 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static double	distance(double x, double y, t_game *game)
{
	return (sqrt(pow(x - game->player->x, 2) + pow(y - game->player->y, 2)));
}

void	horizontal_ray_length(const double ray_angle, t_ray *ray, t_game *game)
{
	ray->h_length = INFINITY;
	if (ray_angle > PI)
	{
		ray->h_y = (int)game->player->y - 0.0000001;
		ray->dy = -1.0;
	}
	else
	{
		ray->h_y = (int)game->player->y + 1.0;
		ray->dy = 1.0;
	}
	ray->h_x = game->player->x + (ray->h_y - game->player->y) / tan(ray_angle);
	ray->dx = ray->dy / tan(ray_angle);
	while ((int)ray->h_x >= 0 && (int)ray->h_x < game->map->map_height
		&& (int)ray->h_y >= 0 && (int)ray->h_y < game->map->map_width)
	{
		if (game->map->map[(int)ray->h_x][(int)ray->h_y] < 1)
		{
			ray->h_x += ray->dx;
			ray->h_y += ray->dy;
		}
		else
			break ;
	}
	ray->h_length = distance(ray->h_x, ray->h_y, game);
}

void	vertical_ray_length(const double ray_angle, t_ray *ray, t_game *game)
{
	ray->v_length = INFINITY;
	if (ray_angle > PI / 2 && ray_angle < 3 * PI / 2)
	{
		ray->v_x = (int)game->player->x - 0.0000001;
		ray->dx = -1.0;
	}
	else
	{
		ray->v_x = (int)game->player->x + 1.0;
		ray->dx = 1.0;
	}
	ray->v_y = game->player->y + (ray->v_x - game->player->x) * tan(ray_angle);
	ray->dy = ray->dx * tan(ray_angle);
	while ((int)ray->v_x >= 0 && (int)ray->v_x < game->map->map_height
		&& (int)ray->v_y >= 0 && (int)ray->v_y < game->map->map_width)
	{
		if (game->map->map[(int)ray->v_x][(int)ray->v_y] < 1)
		{
			ray->v_x += ray->dx;
			ray->v_y += ray->dy;
		}
		else
			break ;
	}
	ray->v_length = distance(ray->v_x, ray->v_y, game);
}
