/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:37:37 by vblanc            #+#    #+#             */
/*   Updated: 2025/09/19 14:08:48 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "main.h"
#include "parsing.h"
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
	if (parsing(ac, av, game))
	{
		printf("Error during parsing\n");
		clear_parsing(game);
		return (1);
	}
	mlx_loop_hook(game->mlx->mlx_ptr, loop_hook, game);
	mlx_loop(game->mlx->mlx_ptr);
	return (0);
}
