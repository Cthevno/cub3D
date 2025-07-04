/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:01:47 by ctheveno          #+#    #+#             */
/*   Updated: 2025/06/27 11:25:09 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char )c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*sdup;
	int		i;

	sdup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (sdup == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		sdup[i] = s[i];
		i++;
	}
	sdup[i] = '\0';
	return (sdup);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	lens1;
	size_t	lens2;

	i = 0;
	lens1 = ft_strlen((char *)s1);
	lens2 = ft_strlen((char *)s2);
	s3 = malloc(sizeof(s3) * (lens1 + lens2 + 1));
	if (!s3)
		return (free(s1), NULL);
	while (i < lens1)
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < lens2)
	{
		s3[lens1 + i] = s2[i];
		i++;
	}
	s3[lens1 + lens2] = '\0';
	free(s1);
	return (s3);
}
