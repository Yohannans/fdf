/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:25:13 by yansquer          #+#    #+#             */
/*   Updated: 2025/01/12 19:49:08 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(t_3dpoint *a, double gamma)
{
	int	tmp;

	tmp = a->x;
	a->x = tmp * cos(gamma) - a->y * sin(gamma);
	a->y = tmp * sin(gamma) + a->y * cos(gamma);
}

void	rotate_y(t_3dpoint *a, double tetha)
{
	int	tmp;

	tmp = a->x;
	a->x = tmp * cos(tetha) + a->z * sin(tetha);
	a->z = a->z * cos(tetha) - tmp * sin(tetha);
}

void	rotate_x(t_3dpoint *a, double alpha)
{
	int	tmp;

	tmp = a->y;
	a->y = tmp * cos(alpha) - a->z * sin(alpha);
	a->z = tmp * sin(alpha) + a->z * cos(alpha);
}

void	rotate(t_matrixofpoints *matrix, double alpha, double tetha,
		double gamma)
{
	t_matrixofpoints *cursor;

	cursor = matrix;
	while (cursor)
	{
		rotate_x(&cursor->point, alpha);
		rotate_y(&cursor->point, tetha);
		rotate_z(&cursor->point, gamma);
		cursor = cursor->next;
	}
}