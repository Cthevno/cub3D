/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:32:46 by vblanc            #+#    #+#             */
/*   Updated: 2025/09/19 13:59:03 by vblanc           ###   ########.fr       */
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

int	loop_hook(t_game *game)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	new_image(game);
	gettimeofday(&end, NULL);
	hooks_handler(game);
	sprite_manager(game);
	return (0);
}
