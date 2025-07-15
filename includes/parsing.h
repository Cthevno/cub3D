#ifndef PARSING_H
# define PARSING_H
#include <stdlib.h>

// typedef struct s_map
// {
// 	// Map representation
// 	int	**map;
// 	int	map_width;
// 	int	map_height;

// 	// Map textures and colors
// 	int	**texture_north;
// 	int	**texture_south;
// 	int	**texture_east;
// 	int	**texture_west;
// 	int	**texture_door;
// 	int	***texture_sprite;
// 	int	floor_color;
// 	int	ceiling_color;
// }		t_map;

typedef struct s_map_path
{
	// Map representation
	char	*file_path;
	char		**map;
	int		map_width;
	int		map_height;

	// Map textures and colors
	char	*path_texture_north;
	char	*path_texture_south;
	char	*path_texture_east;
	char	*path_texture_west;
	char	*path_texture_door;
	int	***texture_sprite;
	int	floor_color;
	int	ceiling_color;
}		t_map_path;

// int	parsing(int ac, char **av);
int	ft_error(char *str);
void	*ft_error_null(char *str);
size_t	find_path_start(char *str);
size_t	get_path_len(char *str);
int	get_path(char c, char *str, t_map_path *map);
int	clean_line(char *str);
void	*clean_map(t_map_path *map);
size_t	get_rgb_colour(char c,char *str, t_map_path *map);
int	find_map_grid_start(int	i, int fd, char *line);
int	extract_map_grid(int i, t_map_path *map);
int	map_is_valid(t_map_path *map);
void	get_to_the_start_of_map_grid(int fd, int i);
int	find_map_grid_start(int i, int fd, char *line);

#endif
