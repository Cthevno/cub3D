#include "../gnl/get_next_line.h"
#include "../libft/libft.h"
#include "../printf_fd_buffer/header/ft_printf.h"
#include <stdio.h>
#include "./parsing.h"
#include <limits.h>


void	ft_free(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

void	ft_free_doble_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}

int	ft_safe_atoi(const char *nptr, int *result)
{
	long	value;
	int		sign;

	value = 0;
	sign = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		value = value * 10 + (*nptr - '0');
		if (value * sign > INT_MAX || value * sign < INT_MIN)
			return (0);
		nptr++;
	}
	if (*nptr != '\0')
		return (0);
	*result = (int)(value * sign);
	return (1);
}

int	is_white_space(char c)
{
	int	white_space;

	white_space = 0;
	if (c == ' ' || c == '\t' || c == '\n')
		white_space = 1;
	else if (c == '\v' || c == '\f' || c == '\r')
		white_space = 1;
	return (white_space);
}

int	ft_error(char *str)
{
	ft_printf_fd(2, "%s\n", str);
	return (0);
}

void	*ft_error_null(char *str)
{
	ft_printf_fd(2, "%s\n", str);
	return (NULL);
}


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

size_t	find_path_start(char *str)
{
	size_t	move;

	move = 0;
	while (str && !is_white_space(*str))
	{
		move++;
		str++;
	}
	while (str && is_white_space(*str))
	{
		move++;
		str++;
	}
	return (move);
}

size_t	get_path_len(char *str)
{
	size_t	len;
	// printf("get_path_len : %s\n", str);
	len = 0;
	while (str && *str)
	{
		// write(1, str, 1);
		if (is_white_space(*str))
			break ;
		len++;
		str++;
	}
	// write(1, "\n", 1);
	// printf("len : %zu\n", len);
	return (len);
}

static void	update_map_paths(t_map_path *map, char c, char *str)
{
	if (c == 'N')
		map->path_texture_north = str;
	else if (c == 'S')
		map->path_texture_south = str;
	else if (c == 'E')
		map->path_texture_east = str;
	else if (c == 'W')
		map->path_texture_west = str;
}

static int	get_path(char c, char *str, t_map_path *map)
{
	size_t	len;
	char	*copy_path;
	size_t	i;

	len = 0;
	len += find_path_start(str);
	str += find_path_start(str);
	len += get_path_len(str);
	copy_path = NULL;
	copy_path = malloc(sizeof(char) * len +1);
	if (!copy_path)
		return (len);
	i = 0;
	while (i < len)//strncpy
	{
		if (*str == '\n' || is_white_space(*str))
			break ;
		copy_path[i] = *str;
		i++;
		str++;
	}
	copy_path[i] = '\0';
	update_map_paths(map, c, copy_path);
	return (len);
}

char	**split_rgb_values(char *str)
{
	char	**dest;
	char	*temp;
	int		i;

	i = 0;
	temp = str;
	while (temp && *temp)
	{
		if (*temp == ',')
			i++;
		temp++;
	}
	if (i != 2)
		return (NULL);
	dest = ft_split(str, ',');
	free(str);
	return (dest);
}
char	**get_rgb_colour_strings(char *str)
{
	size_t	len;
	char	*copy_path;
	size_t	i;

	len = 0;
	len += find_path_start(str);
	str += find_path_start(str);
	len += get_path_len(str);
	copy_path = NULL;
	copy_path = malloc(sizeof(char) * len +1);
	if (!copy_path)
		return (NULL);
	i = 0;
	while (i < len)//strncpy
	{
		if (*str == '\n' || is_white_space(*str))
			break ;
		copy_path[i] = *str;
		i++;
		str++;
	}
	copy_path[i] = '\0';
	return (split_rgb_values(copy_path));
}

static int	get_rgb_colour_int(char **rgb_values_strings)
{
	int	r;
	int	g;
	int	b;

	r = - 1;
	g = - 1;
	b = - 1;
	ft_safe_atoi(rgb_values_strings[0], &r);
	ft_safe_atoi(rgb_values_strings[1], &g);
	ft_safe_atoi(rgb_values_strings[2], &b);
	printf("r : %d g : %d b : %d\n", r, g, b);
	ft_free_doble_tab(rgb_values_strings);
	if ((r < 0 || r > 255) || ((g < 0 || g > 255)) ||
		(b < 0 || b > 255))
		return (-1);
	return ((r << 16) | (g << 8) | b);
}

static size_t	get_rgb_colour(char c,char *str, t_map_path *map)
{
	size_t	move;
	char	**rgb_values_strings;

	move = 0;
	move += find_path_start(str);
	move += get_path_len(str);
	rgb_values_strings = NULL;
	rgb_values_strings = get_rgb_colour_strings(str);
	if (c == 'F')
		map->floor_color = get_rgb_colour_int(rgb_values_strings);
	if (c == 'C')
		map->ceiling_color = get_rgb_colour_int(rgb_values_strings);
	// ft_free_doble_tab(rgb_values_strings);
	return (move);
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



static int	clean_line(char *str)
{
	ft_free(&str);
	return (0);
}

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

void	*clean_map(t_map_path *map)
{
	// ft_free_doble_tab(map->map);
	// ft_free(map->path_texture_door);
	//free sprite too ***int how to free ?
	ft_free(&map->path_texture_east);
	ft_free(&map->path_texture_north);
	ft_free(&map->path_texture_south);
	ft_free(&map->path_texture_west);
	free(map);
	return (NULL);
}

int	found_first_map_line(char *line)
{
	while (line && *line)
	{
		if (*line == '\n')
			return (0);
		if (*line == '1' || *line == '0')
			break ;
		line++;
	}
	return (1);
}

int	find_map_grid_start(int	i, int fd, char *line)
{
	if (!line)
		return (-1);
	while (line != NULL)
	{
		if (found_first_map_line(line))
		{
			break ;
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	get_next_line(-1);
	// close(fd);
	return (i);
}
void	get_to_the_start_of_map_grid(int fd, int i)
{
	char	*line;
	int		j;

	line = NULL;
	line = get_next_line(fd);
	j = 0;
	while (j < i -1)
	{
		free(line);
		line = get_next_line(fd);
		j++;
	}
	free(line);
}

int	map_grid_size(int i, t_map_path *map)
{
	int		fd;
	char	*line;
	int		map_size;

	fd = open(map->file_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	get_to_the_start_of_map_grid(fd, i);
	line = NULL;
	line = get_next_line(fd);
	map_size = 0;
	while (line != NULL)
	{
		map_size++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	get_next_line(-1);
	close(fd);
	return (map_size);
}

int	ft_copy_map(int start, t_map_path *map, int map_size)
{
	int	fd;
	int	i;
	char *line;
	// size_t	size;
	char	*temp_line;

	fd = open(map->file_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	get_to_the_start_of_map_grid(fd, start);
	line = NULL;
	i = 0;
	while (i < map_size)
	{
		line = get_next_line(fd);
		map->map[i] = malloc (sizeof(char) * (ft_strlen_char(line, '\n') + 1));
		if (!map->map[i])

		ft_strncpy(map->map[i], line, ft_strlen_char(line, '\n'));
		free(line);
		i++;
	}
	return (1);
}

int	extract_map_grid(int i, t_map_path *map)
{
	int		map_size;

	map_size = map_grid_size(i, map);
	map->map = malloc(sizeof(char *) * map_size +1);
	if (!map->map)
		return (0);
	ft_copy_map(i, map, map_size);
	// map_grid = malloc(sizeof(char *) * )
}

// t_map_path	*get_map_data(int fd, char *file_path)
// {
// 	t_map_path	*map;
// 	int			i;
// 	char		*line;

// 	// if (!fd) //Si j'ai la place j'y rajoute
// 		// return (NULL);
// 	map = malloc(sizeof(t_map_path));
// 	if (!map)
// 		return (ft_error_null("Error, malloc failed"));
// 	init_map_path(map, file_path);
// 	line = NULL;
// 	i = 0;
// 	line = get_next_line(fd);
// 	if (line != NULL)
// 	{
// 		while (i < 6)
// 		{
// 			if (extract_map_textures_path(line, map, &i) != 1)
// 			{
// 				ft_free(&line);
// 				return (clean_map(map));
// 			}
// 			free(line);
// 			line = get_next_line(fd);
// 		}
// 		// extract_map_grid(line, map, fd);
// 	}
// 	free(line);
// 	get_next_line(-1); // Free static buffer
// 	return (map);
// }

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

void	print_map_data(t_map_path *map)
{
	printf("N : '%s'\n S : '%s'\n E : '%s'\n W : '%s'\n", map->path_texture_north, map->path_texture_south,
	map->path_texture_east, map->path_texture_west);
	printf("C : %d\n F : %d\n", map->ceiling_color, map->floor_color);
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
