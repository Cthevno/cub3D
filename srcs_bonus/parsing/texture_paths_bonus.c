/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_paths_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:46:23 by ctheveno          #+#    #+#             */
/*   Updated: 2025/09/30 15:17:42 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./parsing_bonus.h"
#include "../../libft/libft.h"

size_t	find_path_start(char *str)
{
	size_t	move;

	move = 0;
	while (str && !is_white_space(*str))
	{
		move++;
		str++;
	}
	while (str && is_white_space(*str))
	{
		if (*str == '\n')
			break ;
		move++;
		str++;
	}
	return (move);
}

size_t	get_path_len(char *str)
{
	size_t	len;

	len = 0;
	while (str && *str)
	{
		if (is_white_space(*str))
			break ;
		len++;
		str++;
	}
	return (len);
}

static void	update_map_paths(t_map_path *map, char c, char *str)
{
	if (c == 'N')
		map->path_texture_north = str;
	else if (c == 'S')
		map->path_texture_south = str;
	else if (c == 'E')
		map->path_texture_east = str;
	else if (c == 'W')
		map->path_texture_west = str;
}

int	get_path(char c, char *str, t_map_path *map)
{
	size_t	len;
	char	*copy_path;
	size_t	i;

	len = 0;
	str += find_path_start(str);
	len += get_path_len(str);
	copy_path = NULL;
	copy_path = malloc(sizeof(char) * len +1);
	if (!copy_path)
		return (len);
	i = 0;
	while (i < len)
	{
		if (*str == '\n' || is_white_space(*str))
			break ;
		copy_path[i] = *str;
		i++;
		str++;
	}
	copy_path[i] = '\0';
	update_map_paths(map, c, copy_path);
	return (len);
}
