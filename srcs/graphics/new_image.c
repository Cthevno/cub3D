/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:03:52 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 12:23:22 by vblanc           ###   ########.fr       */
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

static void	select_texture(t_game *game, int dir, int pixel[2], int texture[2])
{
	int	pixel_color;
	int	***sub_texture_ptr;

	pixel_color = 0;
	if (dir == 0) // North
		pixel_color = game->map->texture_north[texture[0]][texture[1]];
	else if (dir == 2) // South
		pixel_color = game->map->texture_south[texture[0]][texture[1]];
	else if (dir == 1) // East
		pixel_color = game->map->texture_east[texture[0]][texture[1]];
	else if (dir == 3) // West
		pixel_color = game->map->texture_west[texture[0]][texture[1]];
	else if (dir == 4 || dir == 5) // Door
		pixel_color = game->map->texture_door[texture[0]][texture[1]];
	else if (dir == 6 || dir == 7) // Sprite
	{
		sub_texture_ptr = &(game->map->texture_sprite[game->sprite_counter]);
		pixel_color = (*sub_texture_ptr)[texture[0]][texture[1]];
	}
	my_mlx_pixel_put(game->mlx, pixel[0], pixel[1], pixel_color);
}

static void	handle_texture(t_game *game, int x, int dir, double wall_info[2])
{
	const int	start = -(int)(W_HEIGHT / wall_info[0]) / 2 + W_HEIGHT / 2;
	const int	end = (int)(W_HEIGHT / wall_info[0]) / 2 + W_HEIGHT / 2;
	int			texture[2];
	int			pixel[2];

	texture[0] = (int)(wall_info[1] * TEXTURE_SIZE);
	pixel[0] = x;
	pixel[1] = start;
	if (pixel[1] < 0)
		pixel[1] = 0;
	while (pixel[1] < end && pixel[1] < W_HEIGHT)
	{
		texture[1] = ((int)pixel[1] - start) * TEXTURE_SIZE / (end - start);
		select_texture(game, dir, pixel, texture);
		pixel[1]++;
	}
}

static void	draw_line(t_game *game, int x, double wall_d, int dir)
{
	double	camera_shift;
	double	ray_x;
	double	ray_y;
	double	wall_impact;
	double	wall_info[2];

	camera_shift = 2.0 * x * game->camera->width_inv - 1;
	ray_x = game->player->dir_x + game->camera->plane_x * camera_shift;
	ray_y = game->player->dir_y + game->camera->plane_y * camera_shift;
	wall_impact = 0.0;
	if (dir % 2 == 0)
		wall_impact = game->player->y + wall_d * ray_y;
	else
		wall_impact = game->player->x + wall_d * ray_x;
	wall_impact -= (int)wall_impact;
	wall_info[0] = wall_d;
	wall_info[1] = wall_impact;
	handle_texture(game, x, dir, wall_info);
}

int	new_image(t_game *game)
{
	int		x;
	t_dda	*dda_x;

	refresh_image(game);
	x = 0;
	while (x < W_WIDTH)
	{
		dda_x = ft_calloc(1, sizeof(t_dda));
		if (!dda_x)
			continue ;
		dda(x, dda_x, game);
		draw_line(game, x, dda_x->wall_d, dda_x->dir);
		free(dda_x);
		x++;
	}
	minimap(game);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->mlx_win,
		game->mlx->img, 0, 0);
	return (0);
}
