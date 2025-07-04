/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_camera.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:11:44 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/15 20:02:41 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_CAMERA_H
# define S_CAMERA_H

// width_inv:
// Inverse of the width of the camera (1.0 / W_WIDTH)

// plane_x, plane_y:
// Camera plane vector for the 3D projection

typedef struct s_camera
{
	double	width_inv;
	double	plane_x;
	double	plane_y;
}			t_camera;

#endif
