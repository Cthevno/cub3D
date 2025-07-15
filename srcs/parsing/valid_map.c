/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:38:55 by ctheveno          #+#    #+#             */
/*   Updated: 2025/07/15 15:36:54 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../libft/libft.h"
#include <stdio.h>

size_t	ft_doble_tab_size(char **doble_tab)
{
	int		i;
	size_t	size;

	size = 0;
	i = 0;
	while (doble_tab[i])
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_copy_doble_tab(char **doble_tab)
{
	char	**doble_tab_copy;
	size_t	doble_tab_size;
	int		i;

	doble_tab_size = ft_doble_tab_size(doble_tab);
	doble_tab_copy = malloc(sizeof(char *) * (doble_tab_size +1));
	if (!doble_tab_copy)
		return (NULL);
	i = 0;
	while (doble_tab[i])
	{
		doble_tab_copy[i] = malloc(ft_strlen(doble_tab[i]) +1);
		ft_strcpy(doble_tab_copy[i], doble_tab[i]);
		i++;
	}
	doble_tab_copy[i] = NULL;
	return (doble_tab_copy);
}

int	is_direction_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}
static int	start_direction(t_map_path *map)
{
	int	x;
	int	y;
	int	direction_player;

	direction_player = 0;
	x = 0;
	while (map->map[x])
	{
		y = 0;
		while (map->map[x][y])
		{
			if (is_direction_player(map->map[x][y]))
				direction_player++;
			y++;
		}
		x++;
	}
	if (direction_player == 0 || direction_player > 1)
		return (0);
	return (1);
}

void	update_map_copy(char **map, int *x, int *y)
{
	int	updated;

	updated = 0;
	if (map[*x +1][*y] == '0' || map[*x +1][*y] == 'D')
	{
		map[*x +1][*y] = map[*x][*y];
		updated = 1;
	}
	if (map[*x -1][*y] == '0' || map[*x -1][*y] == 'D')
	{
		map[*x -1][*y] = map[*x][*y];
		updated = 1;
	}
	if (map[*x][*y +1] == '0' || map[*x][*y +1] == 'D')
	{
		map[*x][*y +1] = map[*x][*y];
		updated = 1;
	}
	if (map[*x][*y - 1] == '0' || map[*x][*y - 1] == 'D')
	{
		map[*x][*y - 1] = map[*x][*y];
		updated = 1;
	}
	if (updated == 1)
	{
		*x = 0;
		*y = 0;
	}
}
int	flood_neighboors(char **map, int *x, int *y)
{
	int	previous_line;
	int	next_line;
	int	len_previous_line;
	int	len_next_line;

	len_previous_line = 0;
	len_next_line = 0;
	previous_line = *x -1;
	next_line = *x +1;
	if (*x == 0 || *y == 0)
		return (-1);
	if (previous_line >= 0)
		len_previous_line = ft_strlen(map[previous_line]);
	if (map[next_line] != NULL)
		len_next_line = ft_strlen(map[next_line]);
	if (*y > len_next_line || *y > len_previous_line)
		return (-1);
	if (*x == 0 || map[*x +1] == NULL)
		return (-1);
	update_map_copy(map, x, y);
	return (1);
}

int	flood_map(char **map)
{
	int	x;
	int	y;
	// int	flood;

	// flood = 0;
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (is_direction_player(map[x][y]))
			{
				if (flood_neighboors(map, &x, &y) == -1)
					return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

// int	map_enclosed(char **map)
// {

// }

static int	closed_map(t_map_path *map)
{
	char **map_copy;
	// int	return_value;

	map_copy = ft_copy_doble_tab(map->map);
	if (!map_copy)
		return (0);
	if (!flood_map(map_copy))
	{
		ft_free_doble_tab(map_copy);
		return (0);
	}
	// return_value = map_enclosed(map_copy);
	ft_free_doble_tab(map_copy);
	return (1);
}

int	map_is_valid(t_map_path *map)
{
	if (!start_direction(map))
		return (0);
	if (!closed_map(map))
		return (0);
	return (1);
}
