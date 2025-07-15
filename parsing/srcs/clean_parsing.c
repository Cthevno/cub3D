/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:30:49 by ctheveno          #+#    #+#             */
/*   Updated: 2025/07/10 16:30:53 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parsing.h"
#include <stdlib.h>

static int	clean_line(char *str)
{
	ft_free(&str);
	return (0);
}

void	*clean_map(t_map_path *map)
{
	// ft_free_doble_tab(map->map);
	// ft_free(map->path_texture_door);
	//free sprite too ***int how to free ?
	ft_free(&map->path_texture_east);
	ft_free(&map->path_texture_north);
	ft_free(&map->path_texture_south);
	ft_free(&map->path_texture_west);
	free(map);
	return (NULL);
}
