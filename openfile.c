/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:46:04 by yansquer          #+#    #+#             */
/*   Updated: 2025/01/13 11:03:35 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrixofpoints	*newpoint(int x, int y, int z)
{
	t_matrixofpoints	*new;

	new = malloc(sizeof(t_matrixofpoints));
	if (!new)
		return (NULL);
	new->point.x = x;
	new->point.y = y;
	new->point.z = z;
	new->next = NULL;
	return (new);
}

t_matrixofpoints	*addpoint(t_matrixofpoints **matrix, int x, int y, int z)
{
	t_matrixofpoints	*cursor;

	if (!*matrix)
	{
		*matrix = newpoint(x, y, z);
		return (*matrix);
	}
	cursor = *matrix;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = newpoint(x, y, z);
	return (cursor->next);
}

void	parse(t_matrixofpoints **matrix, char *line, int y)
{
	int		x;
	char	**split;

	split = ft_split(line, ' ');
	x = 0;
	while (split[x])
	{
		addpoint(matrix, x, y, ft_atoi(split[x]));
		x++;
	}
	x = 0;
	while (split[x])
	{
		free(split[x]);
		x++;
	}
	free(split);
}

int	readfile(int fd, t_matrixofpoints **matrix)
{
	char	*line;
	int		y;

	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		parse(matrix, line, y);
		y++;
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	openfile(char const *file, t_matrixofpoints **matrix)
{
	int	fd;

	if (ft_strncmp(file + ft_strlen(file) - 4, ".fdf", 4))
		return (0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	readfile(fd, matrix);
	close(fd);
	return (1);
}
