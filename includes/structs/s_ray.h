/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ray.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:55:40 by vblanc            #+#    #+#             */
/*   Updated: 2025/08/21 01:41:31 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_RAY_H
# define S_RAY_H

# define PI 3.14159265358979323846
# define DEG 0.0174533

typedef struct s_ray
{
	double	h_x;
	double	h_y;
	double	v_x;
	double	v_y;
	double	dx;
	double	dy;
	double	h_length;
	double	v_length;
}			t_ray;

#endif
