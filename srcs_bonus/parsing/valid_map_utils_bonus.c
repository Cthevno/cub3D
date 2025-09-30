/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:01:07 by ctheveno          #+#    #+#             */
/*   Updated: 2025/09/16 12:01:18 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	is_accepted_map_char(char c)
{
	if (c == '1' || c == '0' || c == ' ')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else if (c == 'D')
		return (1);
	else if (c == 'C')
		return (1);
	return (0);
}

int	is_direction_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

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
		doble_tab_copy[i] = malloc(ft_strlen(doble_tab[i]) + 1);
		ft_strcpy(doble_tab_copy[i], doble_tab[i]);
		i++;
	}
	doble_tab_copy[i] = NULL;
	return (doble_tab_copy);
}
