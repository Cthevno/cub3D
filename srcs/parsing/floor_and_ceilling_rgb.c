/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceilling_rgb.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:30:59 by ctheveno          #+#    #+#             */
/*   Updated: 2025/09/23 15:53:37 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./parsing.h"
#include "../../libft/libft.h"

char	**split_rgb_values(char *str)
{
	char	**dest;
	char	*temp;
	int		i;

	i = 0;
	temp = str;
	while (temp && *temp)
	{
		if (*temp == ',')
			i++;
		temp++;
	}
	if (i != 2)
		return (NULL);
	dest = ft_split(str, ',');
	free(str);
	return (dest);
}

char	**get_rgb_colour_strings(char *str)
{
	size_t	len;
	char	*copy_path;
	size_t	i;

	len = 0;
	len += find_path_start(str);
	str += find_path_start(str);
	len += get_path_len(str);
	copy_path = NULL;
	copy_path = malloc(sizeof(char) * len +1);
	if (!copy_path)
		return (NULL);
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
	return (split_rgb_values(copy_path));
}

static int	get_rgb_colour_int(char **rgb_values_strings)
{
	int	r;
	int	g;
	int	b;

	r = -1;
	g = -1;
	b = -1;
	ft_safe_atoi(rgb_values_strings[0], &r);
	ft_safe_atoi(rgb_values_strings[1], &g);
	ft_safe_atoi(rgb_values_strings[2], &b);
	ft_free_doble_tab(rgb_values_strings);
	if ((r < 0 || r > 255) || ((g < 0 || g > 255))
		|| (b < 0 || b > 255))
		return (-1);
	return ((r << 16) | (g << 8) | b);
}

static int	valid_colour_string(char **colour_array)
{
	int	i;

	i = 0;
	while (colour_array[i])
		i++;
	if (i != 3)
		return (0);
	return (1);
}

size_t	get_rgb_colour(char c, char *str, t_map_path *map)
{
	size_t	move;
	char	**rgb_values_strings;

	move = 0;
	move += find_path_start(str);
	move += get_path_len(str);
	rgb_values_strings = NULL;
	rgb_values_strings = get_rgb_colour_strings(str);
	if (!valid_colour_string(rgb_values_strings))
	{
		ft_free_doble_tab(rgb_values_strings);
		return (0);
	}
	if (c == 'F')
		map->floor_color = get_rgb_colour_int(rgb_values_strings);
	if (c == 'C')
		map->ceiling_color = get_rgb_colour_int(rgb_values_strings);
	return (move);
}
