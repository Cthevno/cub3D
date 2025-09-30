/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:09:49 by ctheveno          #+#    #+#             */
/*   Updated: 2025/09/30 15:16:31 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf_fd_buffer/header/ft_printf.h"
#include <stdio.h>
#include "./parsing_bonus.h"
#include <limits.h>
#include <fcntl.h>
#include "main.h"

int	check_file_name(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = ft_strlen(str);
	if (len < 5)
		return (0);
	if (ft_strcmp(str + len - 4, ".cub") == 0)
		return (1);
	return (0);
}

t_map_path	*get_map_and_paths(char **av)
{
	int			fd;
	t_map_path	*map;

	if (!check_file_name(av[1]))
		return (ft_error_null("Error with file name"));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_error_null("Error opening file"));
	map = get_map_data(fd, av[1]);
	close (fd);
	if (map == NULL)
		return (NULL);
	if (!map_is_valid(map))
	{
		close(fd);
		printf("map is NOT valid\n");
		clean_map(map);
		return (NULL);
	}
	return (map);
}

int	parsing(int ac, char **av, t_game *game)
{
	t_map_path	*map_path;

	if (ac != 2 || !game)
		return (1);
	map_path = get_map_and_paths(av);
	if (!map_path)
		return (1);
	if (update_game_map_and_player(map_path, game) == 1)
	{
		clean_map(map_path);
		return (1);
	}
	clean_map(map_path);
	return (0);
}
