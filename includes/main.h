/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:07:05 by vblanc            #+#    #+#             */
/*   Updated: 2025/07/15 10:47:39 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "mlx_use.h"
# include "s_dda.h"
# include <stdio.h>
# include <sys/time.h>

int		init_game(t_game **game);
void	fill_camera(t_game *game);
int		loop_hook(t_game *game);
void	dda(int x, t_dda *dda, t_game *game);
int		new_image(t_game *game);
void	minimap(t_game *game);

/* temp */
int		test_fill_game(t_game *game);
/* parsing */
int	parsing(int ac, char **av);

#endif
