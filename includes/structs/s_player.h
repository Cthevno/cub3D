/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_player.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:51:22 by vblanc            #+#    #+#             */
/*   Updated: 2025/08/21 16:59:33 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PLAYER_H
# define S_PLAYER_H

// x, y:
// Coordinates of the player in the map (floating point for sub-pixel accuracy)
// (ex: x = 2.5, y = 3.5 means the player is at (2, 3) in the map

// angle:
// Angle of the player in the map (floating point for sub-pixel accuracy)
//     Face north:  player->angle =       PI;
//     Face south:  player->angle =        0;
//     Face east:   player->angle = - PI / 2;
//     Face west:   player->angle =   PI / 2;

// dx, dy:
// Direction of the player in the map (floating point for sub-pixel accuracy)
// Initialized with cos(angle) and sin(angle) of the player's angle
//     player->dx = cos(player->angle);
//     player->dy = sin(player->angle);

typedef struct s_player
{
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	angle;
}			t_player;

#endif
