#ifndef PARSING_H
# define PARSING_H

typedef struct s_map
{
	// Map representation
	int	**map;
	int	map_width;
	int	map_height;

	// Map textures and colors
	int	**texture_north;
	int	**texture_south;
	int	**texture_east;
	int	**texture_west;
	int	**texture_door;
	int	***texture_sprite;
	int	floor_color;
	int	ceiling_color;
}		t_map;

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

#endif
