/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:09:36 by ctheveno          #+#    #+#             */
/*   Updated: 2025/09/30 14:22:47 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "main.h"
# include <stdlib.h>
# include "s_parsing.h"

int			ft_error(char *str);
void		*ft_error_null(char *str);
size_t		find_path_start(char *str);
size_t		get_path_len(char *str);
int			get_path(char c, char *str, t_map_path *map);
int			clean_line(char *str);
void		*clean_map(t_map_path *map);
size_t		get_rgb_colour(char c, char *str, t_map_path *map);
int			find_map_grid_start(int i, int fd, char *line);
int			extract_map_grid(int i, t_map_path *map);
int			map_is_valid(t_map_path *map);
void		get_to_the_start_of_map_grid(int fd, int i);
int			find_map_grid_start(int i, int fd, char *line);
int			ft_map_height(char **map);
int			ft_map_width(char **map);
int			store_pixels_from_xpm(char *img_path, int ***texture_array,
				void *mlx_ptr);
int			update_game_map_and_player(t_map_path *map_paths, t_game *game);
t_map_path	*get_map_and_paths(char **av);
int			parsing(int ac, char **av, t_game *game);
int			flood_map(char **map);
int			is_player(char c);
int			is_direction_player(char c);
int			is_accepted_map_char(char c);
int			extract_map_textures_path(char *str, t_map_path *map);
t_map_path	*get_map_data(int fd, char *file_path);
int			**map_char_to_int(char **map_char, int height, int width);
size_t		ft_doble_tab_size(char **doble_tab);
char		**ft_copy_doble_tab(char **doble_tab);
void		clear_parsing(t_game *game);

#endif
