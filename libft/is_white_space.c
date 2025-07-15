/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_white_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:32:17 by ctheveno          #+#    #+#             */
/*   Updated: 2025/07/10 16:32:20 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
