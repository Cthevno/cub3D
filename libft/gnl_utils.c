/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:54:20 by ctheveno          #+#    #+#             */
/*   Updated: 2025/02/04 10:55:37 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	l;

	l = 0;
	while (str && str[l] && str[l] != '\n')
		l++;
	if (str && str[l] == '\n')
		l++;
	return (l);
}

char	*scpy_gnl(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	schr_gnl(const char *s, int c)
{
	size_t	i;
	char	tmp;

	i = 0;
	tmp = (unsigned char)c;
	while (s[i] && s[i] != tmp)
		i++;
	if (s[i] == tmp)
		return (i + 1);
	return (0);
}

char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!dest)
		return (free(s1), NULL);
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2 && *s2 && *s2 != '\n')
	{
		dest[i] = *s2;
		i++;
		s2++;
	}
	if (s2 && *s2 == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
	return (free(s1), dest);
}
