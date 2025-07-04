/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:57:35 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/14 20:36:25 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MLX_H
# define S_MLX_H

// mlx_ptr:
// Pointer to the MLX instance (created with mlx_init)

// mlx_win:
// Pointer to the MLX window (created with mlx_new_window)

// img:
// Pointer to the MLX image (created with mlx_new_image)

// addr:
// Pointer to the image data (used for pixel manipulation)

// bpp:
// Bits per pixel of the image (usually 32 for RGBA)

// line_length:
// Length of a line in bytes (used for pixel manipulation)

// endian:
// Endianness of the pixel data (0 for little-endian, 1 for big-endian)

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_mlx;

#endif
