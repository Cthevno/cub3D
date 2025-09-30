/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texture_paths.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:58:46 by ctheveno          #+#    #+#             */
/*   Updated: 2025/09/23 16:16:02 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "./parsing.h"

static int	is_texture_id(const char *str, char id1, char id2)
{
	if (str[0] != id1)
		return (0);
	if (str[1] != id2)
		return (0);
	if (!is_white_space(str[2]))
		return (0);
	return (1);
}

static int	handle_texture_path(char *str, t_map_path *map)
{
	if (is_texture_id(str, 'N', 'O'))
		return (get_path('N', str, map));
	if (is_texture_id(str, 'S', 'O'))
		return (get_path('S', str, map));
	if (is_texture_id(str, 'W', 'E'))
		return (get_path('W', str, map));
	if (is_texture_id(str, 'E', 'A'))
		return (get_path('E', str, map));
	return (0);
}

//Check the presence of 2 commas before trying to split it later
static int	possibly_valid_coulour_value(char *str)
{
	int	comma;

	comma = 0;
	if (!str)
		return (0);
	str += find_path_start(str);
	while (str && *str)
	{
		if (*str == ',')
			comma++;
		else if (is_white_space(*str))
			break ;
		str++;
	}
	return (comma);
}

static int	handle_color(char *str, t_map_path *map)
{
	if (str[0] == 'F' && (is_white_space(str[1]) && str[1] != '\n'))
	{
		if (possibly_valid_coulour_value(str) != 2)
			return (0);
		return (get_rgb_colour('F', str, map));
	}
	if (str[0] == 'C' && (is_white_space(str[1]) && str[1] != '\n'))
	{
		if (possibly_valid_coulour_value(str) != 2)
			return (0);
		return (get_rgb_colour('C', str, map));
	}
	return (0);
}

// Function to extract textures paths
// and colors and store them inside t_map_path struct

int	extract_map_textures_path(char *str, t_map_path *map)
{
	int	ret;

	if (!str)
		return (0);
	if (*str == '\n')
		return (2);
	while (str && *str)
	{
		ret = handle_texture_path(str, map);
		if (ret)
		{
			str += ret;
			return (1);
		}
		ret = handle_color(str, map);
		if (ret)
		{
			str += ret;
			return (1);
		}
		if (!is_white_space(*str))
			return (0);
		str++;
	}
	return (1);
}
