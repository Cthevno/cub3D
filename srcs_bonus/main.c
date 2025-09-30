/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:37:37 by vblanc            #+#    #+#             */
/*   Updated: 2025/09/22 15:03:19 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "main.h"
#include "parsing_bonus.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	t_game	*game;

	game = NULL;
	if (init_game(&game))
	{
		printf("Error initializing game\n");
		return (1);
	}
	if (parsing(ac, av, game) != 0)
	{
		printf("Error during parsing\n");
		clear_parsing(game);
		return (1);
	}
	mlx_loop_hook(game->mlx->mlx_ptr, loop_hook, game);
	mlx_loop(game->mlx->mlx_ptr);
	return (0);
}
