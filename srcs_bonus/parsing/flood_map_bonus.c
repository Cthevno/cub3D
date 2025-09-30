/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:08:59 by ctheveno          #+#    #+#             */
/*   Updated: 2025/09/16 15:05:16 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing_bonus.h"

static void	update_x_y_map_copy(int *x, int *y)
{
	*x = 0;
	*y = 0;
}

/*m = map*/
static void	update_map_copy(char **m, int *x, int *y)
{
	int	updated;

	updated = 0;
	if (m[*x +1][*y] == '0' || m[*x +1][*y] == 'D' || m[*x +1][*y] == ' ')
	{
		m[*x +1][*y] = m[*x][*y];
		updated = 1;
	}
	if (m[*x -1][*y] == '0' || m[*x -1][*y] == 'D' || m[*x -1][*y] == ' ')
	{
		m[*x -1][*y] = m[*x][*y];
		updated = 1;
	}
	if (m[*x][*y +1] == '0' || m[*x][*y +1] == 'D' || m[*x][*y +1] == ' ')
	{
		m[*x][*y +1] = m[*x][*y];
		updated = 1;
	}
	if (m[*x][*y - 1] == '0' || m[*x][*y - 1] == 'D' || m[*x][*y - 1] == ' ')
	{
		m[*x][*y - 1] = m[*x][*y];
		updated = 1;
	}
	if (updated == 1)
		update_x_y_map_copy(x, y);
}

static int	flood_neighboors(char **map, int *x, int *y)
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
	if (*y > (len_next_line -1) || *y > (len_previous_line -1)
		|| map[*x][*y +1] == 0)
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

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (!is_accepted_map_char(map[x][y]))
				return (0);
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
