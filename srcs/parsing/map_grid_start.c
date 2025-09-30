/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grid_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:06:46 by ctheveno          #+#    #+#             */
/*   Updated: 2025/09/30 14:23:10 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parsing.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

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

int	find_map_grid_start(int i, int fd, char *line)
{
	if (!line)
		return (-1);
	while (line != NULL)
	{
		if (found_first_map_line(line))
			break ;
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
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
