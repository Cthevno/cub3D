/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_char_to_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:36:43 by ctheveno          #+#    #+#             */
/*   Updated: 2025/09/16 12:03:03 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
Walls = 1;
Spaces, 0 and player -> 0;
*/

static int	**clean_backward(int **map_copy, int last_allocated_index)
{
	while (last_allocated_index >= 0)
	{
		free(map_copy[last_allocated_index]);
		last_allocated_index--;
	}
	free(map_copy);
	return (NULL);
}

static void	map_char_to_int_loop(char **m_char, int **m_copy, int width, int i)
{
	int	j;

	j = 0;
	while (1)
	{
		if (m_char[i][j] == '\0')
		{
			while (j < width)
			{
				m_copy[i][j] = 0;
				j++;
			}
			break ;
		}
		else if (m_char[i][j] == '1')
			m_copy[i][j] = 1;
		else
			m_copy[i][j] = 0;
		j++;
	}
}

int	**map_char_to_int(char **map_char, int height, int width)
{
	int	**map_copy;
	int	i;

	map_copy = malloc(sizeof(int *) * height);
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map_copy[i] = malloc(sizeof(int) * width);
		if (!map_copy[i])
			return (clean_backward(map_copy, i));
		map_char_to_int_loop(map_char, map_copy, width, i);
		i++;
	}
	return (map_copy);
}
