/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_game.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:58:47 by vblanc            #+#    #+#             */
/*   Updated: 2025/08/21 16:21:52 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_GAME_H
# define S_GAME_H

# include "s_map.h"
# include "s_mlx.h"
# include "s_player.h"
# include "s_ray.h"
# include <stdbool.h>

// map:
// Pointer to the map struct containing the map data
// Should be filled during parsing

// player:
// Pointer to the player struct containing the player data
// Should be filled during parsing

// ray:
// Pointer to the ray struct containing the ray data
// Should NOT be filled during parsing

// mlx:
// Pointer to the mlx struct containing the mlx data
// Should NOT be filled during parsing

# define HOOKS_NUM 7

typedef enum e_hooks
{
	W = 0,
	S = 1,
	A = 2,
	D = 3,
	LEFT = 4,
	RIGHT = 5,
	SPACE = 6,
}				t_hooks;

typedef struct s_game
{
	int			sprite_count;
	bool		hooks[HOOKS_NUM];

	t_map		*map;
	t_player	*player;
	t_ray		*ray;
	t_mlx		*mlx;
}				t_game;

#endif
