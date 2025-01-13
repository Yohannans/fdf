/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:34:07 by yansquer          #+#    #+#             */
/*   Updated: 2025/01/13 11:05:09 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_image *data, t_2dpoint p, int color)
{
	char	*pxl;

	// Ok, premiere fois que je fais un commentaire mais c'est important
	// D'abord on check que les coordonnees de notre pixel sont
	// coherente avec la taille de la fenetre
	if (p.x >= 0 && p.x < WIN_W && p.y >= 0 && p.y < WIN_H)
	{
		// Ici avec les coordonnees on recupere l'adresse du pixel dont on
		// souhaite changer la couleur
		pxl = data->addr + ((int)p.y * data->size_line + (int)p.x * (data->bits_per_pixel
					/ 8));
		// Ensuite on assigne la nouvelle couleur a ce pixel
		*(unsigned int *)pxl = color;
	}
}

void	ft_draw_line(t_image *data, t_line line)
{
	t_draw_line	draw;
	t_2dpoint	point;

	draw.delta_x = line.b.x - line.a.x;
	draw.delta_y = line.b.y - line.a.y;
	draw.step = sqrt((draw.delta_x * draw.delta_x) + (draw.delta_y
				* draw.delta_y));
	draw.delta_x = draw.delta_x / draw.step;
	draw.delta_y = draw.delta_y / draw.step;
	draw.x = line.a.x;
	draw.y = line.a.y;
	draw.i = 0;
	while (draw.i < draw.step)
	{
		point.x = draw.x;
		point.y = draw.y;
		ft_put_pixel(data, point, line.color);
		draw.x += draw.delta_x;
		draw.y += draw.delta_y;
		(draw.i)++;
	}
}

void	ft_draw_matrix(t_image *data, t_matrixofpoints *matrix)
{
	t_matrixofpoints *cursor;
	t_matrixofpoints *second_cursor;
	t_line line;
    cursor = matrix;
    while (cursor)
    {
        cursor->projected_point.x *= 20;
        cursor->projected_point.y *= 20;
        cursor->projected_point.x += 500;
        cursor->projected_point.y += 300;
        cursor = cursor->next;
    }
    

	cursor = matrix;
	while (cursor)
	{
        ft_put_pixel(data, cursor->projected_point, 0xFFFFFF);
		if (cursor->next && cursor->next->point.x == cursor->point.x + 1)
		{
            
			line.a = cursor->projected_point;
			line.b = cursor->next->projected_point;
			line.color = 0xFFFFFF;
			ft_draw_line(data, line);
		}
		second_cursor = cursor->next;
		while (second_cursor)
		{
			if (cursor->point.x == second_cursor->point.x)
			{
				line.a = cursor->projected_point;
				line.b = second_cursor->projected_point;
				line.color = 0xFFFFFF;
				ft_draw_line(data, line);
				break ;
			}
			second_cursor = second_cursor->next;
		}
        cursor = cursor->next;
	}
}