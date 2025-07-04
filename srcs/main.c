/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:37:37 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 12:43:00 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(void)
{
	t_game	*game;

	game = NULL;
	if (init_game(&game))
	{
		printf("Error initializing game\n");
		return (1);
	}
	if (test_fill_game(game))
		return (1);
	fill_camera(game);
	mlx_loop_hook(game->mlx->mlx_ptr, loop_hook, game);
	mlx_loop(game->mlx->mlx_ptr);
	return (0);
}
