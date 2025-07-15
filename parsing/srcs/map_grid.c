/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:30:34 by ctheveno          #+#    #+#             */
/*   Updated: 2025/07/10 16:30:37 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parsing.h"
#include <stdlib.h>
#include <fcntl.h>

int	found_first_map_line(char *line)
{
	while (line && *line)
	{
		if (*line == '\n')
			return (0);
		if (*line == '1' || *line == '0')
			break ;
		line++;
	}
	return (1);
}

int	find_map_grid_start(int	i, int fd, char *line)
{
	if (!line)
		return (-1);
	while (line != NULL)
	{
		if (found_first_map_line(line))
		{
			break ;
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	// get_next_line(-1);
	// close(fd);
	return (i);
}
void	get_to_the_start_of_map_grid(int fd, int i)
{
	char	*line;
	int		j;

	line = NULL;
	line = get_next_line(fd);
	j = 0;
	while (j < i -1)
	{
		free(line);
		line = get_next_line(fd);
		j++;
	}
	free(line);
}

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

int	ft_copy_map(int start, t_map_path *map, int map_size)
{
	int	fd;
	int	i;
	char *line;
	// size_t	size;
	// char	*temp_line;

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
		// if (!map->map[i])
			//fuck
		ft_strncpy(map->map[i], line, ft_strlen_char(line, '\n'));
		free(line);
		i++;
	}
	map->map[i] = '\0';
	return (1);
}

int	extract_map_grid(int i, t_map_path *map)
{
	int		map_size;

	map_size = map_grid_size(i, map);
	map->map = malloc(sizeof(char *) * map_size +1);
	if (!map->map)
		return (0);
	ft_copy_map(i, map, map_size);
	return (1);
	// map_grid = malloc(sizeof(char *) * )
}
