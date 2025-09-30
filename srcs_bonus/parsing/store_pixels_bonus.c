/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_pixels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:53:05 by ctheveno          #+#    #+#             */
/*   Updated: 2025/09/11 14:33:38 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include "parsing_bonus.h"

static int	store_pixels_loop_helper(t_pixel_storing p_s, int ***texture_array)
{
	int	i;
	int	j;

	i = 0;
	while (i < p_s.height)
	{
		(*texture_array)[i] = malloc(p_s.width * sizeof(int));
		if (!(*texture_array)[i])
			return (0);
		j = 0;
		while (j < p_s.width)
		{
			(*texture_array)[i][j] = *(int *)(p_s.img_data
					+ (i * p_s.size_line + j * (p_s.bits_per_pixel / 8)));
			j++;
		}
		i++;
	}
	return (1);
}
/*	t_pixel_storing	p_s; = pixel_storing */

int	store_pixels_from_xpm(char *img_path, int ***texture_array, void *mlx_ptr)
{
	t_pixel_storing	p_s;

	p_s.mlx_ptr = mlx_ptr;
	if (!p_s.mlx_ptr)
		return (1);
	p_s.img_ptr = mlx_xpm_file_to_image(p_s.mlx_ptr,
			img_path, &p_s.width, &p_s.height);
	if (!p_s.img_ptr)
		return (1);
	p_s.img_data = mlx_get_data_addr(p_s.img_ptr, &p_s.bits_per_pixel,
			&p_s.size_line, &p_s.endian);
	*texture_array = malloc(p_s.height * sizeof(int *));
	if (!*texture_array)
	{
		mlx_destroy_image(p_s.mlx_ptr, p_s.img_ptr);
		return (1);
	}
	if (!store_pixels_loop_helper(p_s, texture_array))
		return (1);
	mlx_destroy_image(p_s.mlx_ptr, p_s.img_ptr);
	return (0);
}
