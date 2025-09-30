/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:03:52 by vblanc            #+#    #+#             */
/*   Updated: 2025/09/10 14:05:26 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	refresh_image(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < W_HEIGHT / 2)
	{
		x = 0;
		while (x < W_WIDTH)
			my_mlx_pixel_put(game->mlx, x++, y, game->map->ceiling_color);
		y++;
	}
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
			my_mlx_pixel_put(game->mlx, x++, y, game->map->floor_color);
		y++;
	}
}

static void	select_texture(int ***texture, t_game *game)
{
	if (game->ray->h_length < game->ray->v_length)
	{
		if (game->map->map[(int)game->ray->h_x][(int)game->ray->h_y] == 2)
			(*texture) = game->map->texture_door;
		else if (game->map->map[(int)game->ray->h_x][(int)game->ray->h_y] == 3)
			(*texture) = game->map->texture_sprite[game->sprite_count];
		else if (game->ray->h_y > game->player->y)
			(*texture) = game->map->texture_west;
		else
			(*texture) = game->map->texture_east;
	}
	else
	{
		if (game->map->map[(int)game->ray->v_x][(int)game->ray->v_y] == 2)
			(*texture) = game->map->texture_door;
		else if (game->map->map[(int)game->ray->v_x][(int)game->ray->v_y] == 3)
			(*texture) = game->map->texture_sprite[game->sprite_count];
		else if (game->ray->v_x < game->player->x)
			(*texture) = game->map->texture_north;
		else
			(*texture) = game->map->texture_south;
	}
}

static void	draw_wall(int x, int y, int texture_x, t_game *game)
{
	int	**texture;
	int	texture_y;
	int	texture_color;

	texture_y = 0;
	texture = NULL;
	select_texture(&texture, game);
	if (game->ray->h_length < game->ray->v_length)
		texture_y = (game->ray->h_x - (int)game->ray->h_x) * TEXTURE_SIZE;
	else
		texture_y = (game->ray->v_y - (int)game->ray->v_y) * TEXTURE_SIZE;
	texture_color = texture[texture_x][texture_y];
	my_mlx_pixel_put(game->mlx, x, y, texture_color);
}

static void	draw_line(int x, double ray_angle, t_ray *ray, t_game *game)
{
	const double	fish_eye = cos(game->player->angle - ray_angle);
	double			wall_height;
	int				y;
	int				start;
	int				end;

	wall_height = W_HEIGHT / (fmin(ray->h_length, ray->v_length) * fish_eye);
	start = (W_HEIGHT - wall_height) / 2;
	end = (W_HEIGHT + wall_height) / 2;
	y = fmax(0, start);
	while (y < end && y < W_HEIGHT)
	{
		draw_wall(x, y, (int)((y - start) * TEXTURE_SIZE / (end - start)),
			game);
		y++;
	}
}

int	new_image(t_game *game)
{
	double	ray_angle;
	int		x;

	refresh_image(game);
	ray_angle = mod_2pi(game->player->angle - DEG * FOV / 2);
	x = 0;
	while (x < W_WIDTH)
	{
		horizontal_ray_length(ray_angle, game->ray, game);
		vertical_ray_length(ray_angle, game->ray, game);
		draw_line(W_WIDTH - x - 1, ray_angle, game->ray, game);
		ray_angle = mod_2pi(ray_angle + DEG * FOV / W_WIDTH);
		x++;
	}
	minimap(game);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->mlx_win,
		game->mlx->img, 0, 0);
	return (0);
}
