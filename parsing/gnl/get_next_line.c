/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:35:15 by ctheveno          #+#    #+#             */
/*   Updated: 2025/07/02 13:29:29 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_left(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	if (!str)
		return (free(str), NULL);
	while (str[i] != '\n')
	{
		if (str[i] == '\0')
			return (free(str), NULL);
		i++;
	}
	if (str[i + 1] == 0)
		return (free(str), NULL);
	dest = ft_strdup(&str[i + 1]);
	if (!dest)
		return (free(str), NULL);
	return (free(str), dest);
}

char	*ft_line(char *str)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str && str[i])
	{
		if (str[i++] == '\n')
			break ;
	}
	dest = malloc(i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		dest[i] = str[i];
		if (str[i++] == '\n')
			break ;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_loop_read(int *bytes_read, char *buffer, int fd, char *str)
{
	while (*bytes_read > 0)
	{
		*bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (*bytes_read < 0)
			return (free (str), NULL);
		buffer[*bytes_read] = 0;
		str = ft_strjoin_gnl(str, buffer);
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (str);
}

char	*clean_static_str(char *str)
{
		if (str)
		{
			free(str);
			str = NULL;
		}
		return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;
	int			bytes_read;
	char		*buffer;

	if (fd == -1)
		return (clean_static_str(str));
	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	str = ft_loop_read(&bytes_read, buffer, fd, str);
	if (!str)
		return (free(buffer), NULL);
	line = ft_line(str);
	str = ft_left(str);
	if (bytes_read == 0 && (!str || str[0] == '\0') && line[0] == '\0')
		return (free(line), free(buffer), NULL);
	return (free(buffer), line);
}
