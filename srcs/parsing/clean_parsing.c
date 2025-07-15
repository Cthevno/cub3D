/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:30:49 by ctheveno          #+#    #+#             */
/*   Updated: 2025/07/15 15:46:07 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parsing.h"
#include "../../libft/libft.h"
#include <stdlib.h>

int	clean_line(char *str)
{
	ft_free(&str);
	return (0);
}

void	*clean_map(t_map_path *map)
{
	ft_free(&map->path_texture_east);
	ft_free(&map->path_texture_north);
	ft_free(&map->path_texture_south);
	ft_free(&map->path_texture_west);
	ft_free_doble_tab(map->map);
	free(map);
	return (NULL);
}
