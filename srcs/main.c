/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:37:37 by vblanc            #+#    #+#             */
/*   Updated: 2025/07/15 10:44:58 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <fcntl.h>
#include "../includes/parsing.h"

int	main(int ac, char **av)
{
	return (parsing(ac, av));
}
// int	main(void)
// {
	// parsing
	// t_game	*game;

	// game = NULL;
	// if (init_game(&game))
	// {
	// 	printf("Error initializing game\n");
	// 	return (1);
	// }
	// if (test_fill_game(game))
	// 	return (1);
	// fill_camera(game);
	// mlx_loop_hook(game->mlx->mlx_ptr, loop_hook, game);
	// mlx_loop(game->mlx->mlx_ptr);
// 	return (0);
// }
