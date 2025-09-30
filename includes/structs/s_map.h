/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:09:14 by vblanc            #+#    #+#             */
/*   Updated: 2025/08/21 16:21:37 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MAP_H
# define S_MAP_H

// map:
// 2D array representing the map;
// 0 for no walls, 1 for walls, 2 for door, 3 for sprite

// map_width, map_height:
// Dimensions of the map

// texture_north, texture_south, texture_east, texture_west, texture_door:
// Textures for the north, south, east, and west walls and the door

// floor_color, ceiling_color:
// Colors for the floor and ceiling

typedef struct s_map
{
	// Map representation
	int	**map;
	int	map_width;
	int	map_height;

	// Map textures and colors
	int	**texture_north;
	int	**texture_south;
	int	**texture_east;
	int	**texture_west;
	int	**texture_door;
	int	***texture_sprite;
	int	floor_color;
	int	ceiling_color;
}		t_map;

#endif
