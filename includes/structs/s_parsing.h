/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_parsing.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:15:26 by ctheveno          #+#    #+#             */
/*   Updated: 2025/09/22 15:16:24 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PARSING_H
# define S_PARSING_H

typedef struct s_pixel_storing
{
	void	*mlx_ptr;
	void	*img_ptr;
	char	*img_data;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		i;
	int		j;
}			t_pixel_storing;

typedef struct s_map_path
{
	char	*file_path;
	char	**map;
	int		map_width;
	int		map_height;
	char	*path_texture_north;
	char	*path_texture_south;
	char	*path_texture_east;
	char	*path_texture_west;
	int		floor_color;
	int		ceiling_color;
}			t_map_path;

#endif