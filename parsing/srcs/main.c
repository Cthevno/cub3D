#include "../gnl/get_next_line.h"
#include "../libft/libft.h"
#include "../printf_fd_buffer/header/ft_printf.h"
#include <stdio.h>
#include "./parsing.h"
#include <limits.h>


int check_file_name(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = ft_strlen(str);
	if (len < 5)
		return (0);
	if (ft_strcmp(str + len - 4, ".cub") == 0)
		return (1);
	return (0);
}


// static int	check_map_paths(t_map_path *map)
// {

// 	if (map->path_texture_north == NULL)
// 		return (0);
// 	if (map->path_texture_south == NULL)
// 		return (0);
// 	if (map->path_texture_east == NULL)
// 		return (0);
// 	if (map->path_texture_west == NULL)
// 		return (0);
// 	// if (map->path_texture_door == NULL)
// 	// 	return (0);
// 	// if (map->texture_sprite == -1)//No idea how this works
// 		// return (0);
// 	if (map->floor_color == -1)
// 		return (0);
// 	if (map->ceiling_color == -1)
// 		return (0);
// 	return (1);
// }


static int	extract_map_textures_path(char *str, t_map_path *map, int *i)
{
	// printf("line : %s\n", str);
	(void)i;
	if (str == NULL)
		return (0);
	if (*str == '\n')
		return (2);
	while (str && *str)
	{
		if (*str == 'N')
		{
			if (*(str +1) == 'O' && is_white_space(*(str +2)))
				str += get_path(*str, str, map);
			else
				return (clean_line(str));
		}
		else if (*str == 'S')
		{
			if (*(str +1) == 'O' && is_white_space(*(str +2)))
				str += get_path(*str, str, map);
			else
				return (clean_line(str));
		}
		else if (*str == 'W')
		{
			if (*(str +1) == 'E' && is_white_space(*(str +2)))
				str += get_path(*str, str, map);
			else
				return (clean_line(str));
		}
		else if (*str == 'E')
		{
			if (*(str +1) == 'A' && is_white_space(*(str +2)))
				str += get_path(*str, str, map);
			else
				return (clean_line(str));
		}
		else if (*str == 'F')
		{
			if (is_white_space(*(str +1)))
				str += get_rgb_colour(*str, str, map);
			else
				return (clean_line(str));
		}
		else if (*str == 'C' && is_white_space(*(str +1)))
		{
			if (is_white_space(*(str +1)))
				str += get_rgb_colour(*str, str, map);
			else
				return (clean_line(str));
		}
		else
			str++;
	}
	// printf("line after : %s\n", str);
	// *i += 1;
	// if (!check_map_paths(map))
	// 	return (0);
	return (1);
}

static void	init_map_path(t_map_path *map, char *file_path)
{
	map->file_path = file_path;
	map->map = NULL; //map_grid
	map->map_width = -1;
	map->map_height = -1;
	map->path_texture_north = NULL;
	map->path_texture_south = NULL;
	map->path_texture_east = NULL;
	map->path_texture_west = NULL;
	map->path_texture_door = NULL;
	map->texture_sprite = NULL;//No idea how this works
	map->floor_color = -1;
	map->ceiling_color = -1;
}

t_map_path	*get_map_data(int fd, char *file_path)
{
	t_map_path	*map;
	int			i;
	int			paths_found;
	char		*line;
	int			result;

	map = malloc(sizeof(t_map_path));
	if (!map)
		return (ft_error_null("Error, malloc failed"));
	init_map_path(map, file_path);
	line = NULL;
	i = 0;
	paths_found = 0;
	line = get_next_line(fd);
	if (line != NULL)
	{
		while (paths_found < 6)
		{
			result = extract_map_textures_path(line, map, &i);
			if (result == 0)
			{
				ft_free(&line);
				return (clean_map(map));
			}
			else if (result == 1)
				paths_found++;
			// else if (result == 2)
			i++;
			free(line);
			line = get_next_line(fd);
		}
		i = find_map_grid_start(i, fd, line);
		if (i == -1)
			return (clean_map(map));
		extract_map_grid(i, map);
	}
	// free(line);
	// get_next_line(-1); // Free static buffer
	return (map);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	printf("----------MAP--------------\n");
	while (map && map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("----------------------------\n");
}

void	print_map_data(t_map_path *map)
{
	printf("N : '%s'\n S : '%s'\n E : '%s'\n W : '%s'\n", map->path_texture_north, map->path_texture_south,
	map->path_texture_east, map->path_texture_west);
	printf("C : %d\n F : %d\n", map->ceiling_color, map->floor_color);
	print_map(map->map);
}

int	main(int ac, char **av)
{
	int	fd;
	t_map_path	*map;

	if (ac != 2)
		return (1);
	if (!check_file_name(av[1]))
		return (ft_error("Error with file name"));
	else
	{
		printf("%s, is a valid file name\n", av[1]);
	}

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_error("Error opening file"));
	map = get_map_data(fd, av[1]);
	close (fd);
	if (map != NULL)
		print_map_data(map);
	else
	{
		printf("error, map is NULL");
		return (1);
	}
	clean_map(map);
	return (0);
}
