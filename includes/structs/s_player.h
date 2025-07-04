/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_player.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:51:22 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/15 17:09:31 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PLAYER_H
# define S_PLAYER_H

// x, y:
// Coordinates of the player in the map (floating point for sub-pixel accuracy)
// (ex: x = 2.5, y = 3.5 means the player is at (2, 3) in the map

// dir_x, dir_y:
// Direction vector of the player (normalized)
//  - dir_x = -1.0, dir_y = 0.0 is facing north
//  - dir_x = 1.0, dir_y = 0.0 is facing south
//  - dir_x = 0.0, dir_y = 1.0 is facing east
//  - dir_x = 0.0, dir_y = -1.0 is facing west

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
}			t_player;

#endif
