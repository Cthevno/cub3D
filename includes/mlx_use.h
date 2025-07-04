/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_use.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:59:49 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 12:36:53 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_USE_H
# define MLX_USE_H

# include "libft.h"
# include "mlx.h"
# include "params.h"
# include "s_game.h"
# include <math.h>

typedef enum e_keys
{
	ESC_MAC = 53,
	ESC_LINUX = 65307,
	W_MAC = 25,
	W_LINUX = 119,
	A_MAC = 0,
	A_LINUX = 97,
	S_MAC = 1,
	S_LINUX = 115,
	D_MAC = 2,
	D_LINUX = 100,
	SPACE_MAC = 49,
	SPACE_LINUX = 32,
	LEFT_MAC = 123,
	LEFT_LINUX = 65361,
	RIGHT_MAC = 124,
	RIGHT_LINUX = 65363
}		t_keys;

typedef enum e_event
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEMOVE = 6,
	ON_DESTROY = 17,
	KeyPressMask = (1L << 0),
	KeyReleaseMask = (1L << 1),
}		t_event;

/* hooks.c */

void	rotate_camera(double angle, t_game *game);
void	move_player(int keycode, t_game *game);
void	move_player_sides(int keycode, t_game *game);
void	open_door(t_game *game);

void	free_array(int **array, int size);

int		init_mlx(t_game *game);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		clear_game(t_game *game);

#endif
