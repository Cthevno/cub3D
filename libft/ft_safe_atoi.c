/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:31:32 by ctheveno          #+#    #+#             */
/*   Updated: 2025/07/10 16:31:36 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

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
