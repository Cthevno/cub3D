/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:09:14 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/30 15:23:03 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MAP_H
# define S_MAP_H

// map:
// 2D array representing the map (0 for no walls, 1 for walls)

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
	/*
	how to convert 220,100,0 in int with bits shifting
	RGB,
	Red : Left most byte used
	Green : middle
	Blue : right most used
	One byte = 8 bits.
	so if colour : 220,100,0
	int red = 220, green = 100, blue = 0;
	colour = (220 << 16) | (100 << 8) | 0; || colour = (red << 16) | (green << 8) | b; || (220 * 2^16) | (100 * 2^8) | 0;
	*/
}		t_map;

#endif
