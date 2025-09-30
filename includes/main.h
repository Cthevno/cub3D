/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:07:05 by vblanc            #+#    #+#             */
/*   Updated: 2025/09/03 09:32:52 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "mlx_use.h"
# include <stdio.h>
# include <sys/time.h>

int		init_game(t_game **game);
int		loop_hook(t_game *game);
int		new_image(t_game *game);
void	minimap(t_game *game);
void	horizontal_ray_length(const double ray_angle, t_ray *ray, t_game *game);
void	vertical_ray_length(const double ray_angle, t_ray *ray, t_game *game);
double	mod_2pi(double x);

/* temp */
int		test_fill_game(t_game *game);
/* parsing */
int		parsing(int ac, char **av, t_game *game);

#endif
