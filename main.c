/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:25:44 by yansquer          #+#    #+#             */
/*   Updated: 2025/01/13 11:04:33 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	graphical_interface(t_matrixofpoints **matrix)
{
	void				*mlx;
	void				*mlx_win;
	double	angle = 0.521;
	t_image				img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIN_W, WIN_H, "fdf");
	// while (1)
	// {
		img.img = mlx_new_image(mlx, WIN_W, WIN_H);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line,
			&img.endian);
		calculate_projection(matrix, angle);
		ft_draw_matrix(&img, *matrix);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		// sleep(1);
		// mlx_destroy_image(mlx, img.img);
		// mlx_clear_window(mlx, mlx_win);
		// rotate(*matrix, 0, 0.1, 0);
	// }
	mlx_loop(mlx);
}

void	print_projected_matrix(t_matrixofpoints *matrix)
{
	t_matrixofpoints	*cursor;

	cursor = matrix;
	while (cursor)
	{
		printf("x: %f, y: %f\n", cursor->projected_point.x,
			cursor->projected_point.y);
		cursor = cursor->next;
	}
}

void	print_matrix(t_matrixofpoints *matrix)
{
	t_matrixofpoints	*cursor;

	cursor = matrix;
	while (cursor)
	{
		ft_printf("x: %d, y: %d, z: %d\n", cursor->point.x, cursor->point.y,
			cursor->point.z);
		cursor = cursor->next;
	}
}

void	fdf(char const *file)
{
	t_matrixofpoints	**matrix;

	matrix = malloc(sizeof(t_matrixofpoints *));
	if (openfile(file, matrix))
	{
		ft_printf("File opened\n");
		//print_matrix(*matrix);
		//calculate_projection(matrix);
		//print_projected_matrix(*matrix);
		graphical_interface(matrix);
		clearmatrix(matrix);
	}
	else
	{
		ft_printf("Error opening file\n");
	}
	free(matrix);
}

int	main(int argc, char const *argv[])
{
	if (argc == 2)
		fdf(argv[1]);
	else
		ft_printf("Wrong number of arguments\n");
	return (0);
}
