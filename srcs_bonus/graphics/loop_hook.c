/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:32:46 by vblanc            #+#    #+#             */
/*   Updated: 2025/09/10 14:10:11 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	hooks_handler(t_game *game)
{
	int	i;

	i = 0;
	while (i < HOOKS_NUM)
	{
		if (game->hooks[i])
		{
			if (i == W)
				move_player(W_MAC, game);
			else if (i == S)
				move_player(S_MAC, game);
			else if (i == A)
				move_player(A_MAC, game);
			else if (i == D)
				move_player(D_MAC, game);
			else if (i == LEFT)
				rotate_camera(KEY_ROT_SPEED, game);
			else if (i == RIGHT)
				rotate_camera(-KEY_ROT_SPEED, game);
		}
		i++;
	}
}

static void	sprite_manager(t_game *game)
{
	static int	count = 0;

	if (count % SPRITE_SPEED < SPRITE_SPEED / 2)
		game->sprite_count = 0;
	else
		game->sprite_count = 1;
	count++;
}

static void	mouse_handler(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_mouse_get_pos(game->mlx->mlx_ptr, game->mlx->mlx_win, &x, &y);
	if (x < (W_WIDTH / 2) - W_HEIGHT * MOUSE_DEAD_ZONE)
		rotate_camera(MOUSE_ROT_SPEED, game);
	else if (x > (W_WIDTH / 2) + W_HEIGHT * MOUSE_DEAD_ZONE)
		rotate_camera(-MOUSE_ROT_SPEED, game);
	mlx_mouse_move(game->mlx->mlx_ptr, game->mlx->mlx_win, W_WIDTH / 2, W_HEIGHT
		/ 2);
}

static void	print_fps(t_game *game, double fps)
{
	char	*str;
	char	*tmp_int;
	char	*tmp_float;
	int		i;
	int		j;

	str = ft_calloc(sizeof(char), 30);
	i = 0;
	tmp_int = ft_itoa(ft_abs((int)fps));
	tmp_float = ft_itoa((int)ft_abs((fps - (int)fps) * 100));
	j = 0;
	while (tmp_int[j])
		str[i++] = tmp_int[j++];
	str[i++] = '.';
	if (ft_strlen(tmp_float) == 1)
		str[i++] = '0';
	j = 0;
	while (tmp_float[j])
		str[i++] = tmp_float[j++];
	free(tmp_int);
	free(tmp_float);
	mlx_string_put(game->mlx->mlx_ptr, game->mlx->mlx_win, 10, 20, 0, "FPS:");
	mlx_string_put(game->mlx->mlx_ptr, game->mlx->mlx_win, 50, 20, 0, str);
	free(str);
}

int	loop_hook(t_game *game)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	new_image(game);
	gettimeofday(&end, NULL);
	print_fps(game, 1000000.0 / (end.tv_usec - start.tv_usec));
	hooks_handler(game);
	sprite_manager(game);
	mouse_handler(game);
	return (0);
}
