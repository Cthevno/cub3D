/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:00:01 by ctheveno          #+#    #+#             */
/*   Updated: 2025/09/30 14:24:29 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"
#include <limits.h>

static void	init_map_path(t_map_path *map, char *file_path)
{
	map->file_path = file_path;
	map->map = NULL;
	map->map_width = -1;
	map->map_height = -1;
	map->path_texture_north = NULL;
	map->path_texture_south = NULL;
	map->path_texture_east = NULL;
	map->path_texture_west = NULL;
	map->floor_color = -1;
	map->ceiling_color = -1;
}

static int	get_map_data_loop(int fd, t_map_path *map, char **line, int *i)
{
	int	paths_found;
	int	result;

	paths_found = 0;
	while (paths_found < 6)
	{
		result = extract_map_textures_path(*line, map);
		if (result == 0)
		{
			ft_free(line);
			if (paths_found != 6)
				printf("Error, one or more texture paths missing\n");
			return (0);
		}
		if (result == 1)
			paths_found++;
		(*i)++;
		ft_free(line);
		*line = get_next_line(fd);
		if (!*line)
			break ;
	}
	return (1);
}

t_map_path	*get_map_data(int fd, char *file_path)
{
	t_map_path	*map;
	int			i;
	char		*line;

	map = malloc(sizeof(t_map_path));
	if (!map)
		return (ft_error_null("Error, malloc failed"));
	init_map_path(map, file_path);
	line = NULL;
	i = 0;
	line = get_next_line(fd);
	if (line != NULL)
	{
		if (!get_map_data_loop(fd, map, &line, &i))
			return (clean_map(map));
		i = find_map_grid_start(i, fd, line);
		if (i == -1)
			return (clean_map(map));
		extract_map_grid(i, map);
	}
	else
		return (clean_map(map));
	return (map);
}
