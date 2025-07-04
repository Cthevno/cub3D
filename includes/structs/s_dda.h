/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_dda.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:19:52 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/15 18:55:20 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_DDA_H
# define S_DDA_H

typedef struct s_dda
{
	double	delta_d[2];
	double	step[2];
	double	side_d[2];
	int		dir;
	double	wall_d;
}			t_dda;

#endif
