/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:56:38 by yansquer          #+#    #+#             */
/*   Updated: 2025/01/12 19:38:32 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clearmatrix(t_matrixofpoints **matrix)
{
	t_matrixofpoints	*cursor;
	t_matrixofpoints	*next;

	cursor = *matrix;
	while (cursor)
	{
		next = cursor->next;
		free(cursor);
		cursor = next;
	}
	*matrix = NULL;
}

void	calculate_projection(t_matrixofpoints **matrix, double angle)
{
	t_matrixofpoints	*cursor;

	cursor = *matrix;
	while (cursor)
	{
		cursor->projected_point.x = (cursor->point.x - cursor->point.y) * cos(angle);
		cursor->projected_point.y = (cursor->point.x + cursor->point.y) * sin(angle) - cursor->point.z;
		cursor = cursor->next;
	}
}
