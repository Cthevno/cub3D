#include <stdlib.h>
#include <limits.h>

// size_t ft_strlen_char(const char *s, char c)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s && s[i] && s[i] != c)
// 		i++;
// 	return (i);
// }

// char	*ft_strncpy(char *dest, const char *src, size_t size)
// {
// 	char	*original_dest;
// 	size_t	i;

// 	i = 0;
// 	original_dest = dest;
// 	while (i < size)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (original_dest);
// }
// void	ft_free(char **str)
// {
// 	if (str && *str)
// 	{
// 		free(*str);
// 		*str = NULL;
// 	}
// }

// void	ft_free_doble_tab(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		if (tab[i])
// 			free(tab[i]);
// 		i++;
// 	}
// 	if (tab)
// 		free(tab);
// }

// int	ft_safe_atoi(const char *nptr, int *result)
// {
// 	long	value;
// 	int		sign;

// 	value = 0;
// 	sign = 1;
// 	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
// 		nptr++;
// 	if (*nptr == '-')
// 	{
// 		sign = -1;
// 		nptr++;
// 	}
// 	else if (*nptr == '+')
// 		nptr++;
// 	while (*nptr >= '0' && *nptr <= '9')
// 	{
// 		value = value * 10 + (*nptr - '0');
// 		if (value * sign > INT_MAX || value * sign < INT_MIN)
// 			return (0);
// 		nptr++;
// 	}
// 	if (*nptr != '\0')
// 		return (0);
// 	*result = (int)(value * sign);
// 	return (1);
// }

// int	is_white_space(char c)
// {
// 	int	white_space;

// 	white_space = 0;
// 	if (c == ' ' || c == '\t' || c == '\n')
// 		white_space = 1;
// 	else if (c == '\v' || c == '\f' || c == '\r')
// 		white_space = 1;
// 	return (white_space);
// }
