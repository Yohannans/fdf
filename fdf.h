/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:18:10 by yansquer          #+#    #+#             */
/*   Updated: 2025/01/13 11:03:26 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_W 1920
# define WIN_H 1080

# include "get_next_line/get_next_line_bonus.h"
# include "minilibx-linux/mlx.h"
# include "simple_printf/includes/ft_printf.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct s_3dpoint
{
	int					x;
	int					y;
	int					z;
}							t_3dpoint;

typedef struct s_2dpoint
{
	double					x;
	double					y;
	// int						color;
}							t_2dpoint;

typedef struct s_matrixofpoints
{
	t_3dpoint				point;
	t_2dpoint				projected_point;
	struct s_matrixofpoints	*next;
}							t_matrixofpoints;

typedef struct s_image
{
	void					*img;
	char					*addr;
	int						bits_per_pixel;
	int						size_line;
	int						endian;
}							t_image;

typedef struct s_line
{
	t_2dpoint				a;
	t_2dpoint				b;
	int						color;
}							t_line;

typedef struct s_draw_line
{
	int						step;
	double					x;
	double					y;
	int						i;
	double					delta_x;
	double					delta_y;
	int						step_color;
}							t_draw_line;

int							openfile(char const *file,
								t_matrixofpoints **matrix);
void						clearmatrix(t_matrixofpoints **matrix);
void						calculate_projection(t_matrixofpoints **matrix,
								double angle);
void						ft_draw_matrix(t_image *data,
								t_matrixofpoints *matrix);
void						rotate(t_matrixofpoints *matrix, double alpha,
								double tetha, double gamma);
#endif