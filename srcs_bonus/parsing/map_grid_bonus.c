/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grid_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:30:34 by ctheveno          #+#    #+#             */
/*   Updated: 2025/09/30 14:24:35 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parsing_bonus.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>

int	map_grid_size(int i, t_map_path *map)
{
	int		fd;
	char	*line;
	int		map_size;

	fd = open(map->file_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	get_to_the_start_of_map_grid(fd, i);
	line = NULL;
	line = get_next_line(fd);
	map_size = 0;
	while (line != NULL)
	{
		map_size++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	get_next_line(-1);
	close(fd);
	return (map_size);
}

static int	handle_malloc_failed(int i, t_map_path *map)
{
	while (i > 0)
	{
		i--;
		free(map->map[i]);
	}
	free(map->map);
	return (0);
}

int	ft_copy_map(int start, t_map_path *map, int map_size)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(map->file_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	get_to_the_start_of_map_grid(fd, start);
	line = NULL;
	i = 0;
	while (i < map_size)
	{
		line = get_next_line(fd);
		map->map[i] = malloc (sizeof(char) * (ft_strlen_char(line, '\n') + 1));
		if (!map->map[i])
		{
			free(line);
			return (handle_malloc_failed(i, map));
		}
		ft_strncpy(map->map[i], line, ft_strlen_char(line, '\n'));
		free(line);
		i++;
	}
	map->map[i] = NULL;
	return (1);
}

int	extract_map_grid(int i, t_map_path *map)
{
	int		map_size;

	map_size = map_grid_size(i, map);
	if (map_size == -1)
		return (0);
	map->map = malloc(sizeof(char *) * (map_size + 1));
	if (!map->map)
		return (0);
	if (!ft_copy_map(i, map, map_size))
		return (0);
	return (1);
}
