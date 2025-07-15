/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:24:13 by ctheveno          #+#    #+#             */
/*   Updated: 2025/07/10 16:29:59 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytesread;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (1)
	{
		if (!buffer[0])
		{
			bytesread = read(fd, buffer, BUFFER_SIZE);
			if (bytesread <= 0)
			{
				if (line != NULL && bytesread != -1)
					return (line);
				return (free(line), NULL);
			}
			buffer[bytesread] = '\0';
		}
		line = ft_strjoin_gnl(line, buffer);
		if (line && schr_gnl(buffer, '\n') != 0)
			return (scpy_gnl(buffer, buffer + schr_gnl(buffer, '\n')), line);
		buffer[0] = '\0';
	}
}
