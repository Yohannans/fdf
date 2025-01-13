/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:11:38 by yansquer          #+#    #+#             */
/*   Updated: 2024/11/19 12:22:45 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	max;

	max = (size_t)-1;
	if (count != 0)
	{
		if (max / count < size)
			return (NULL);
	}
	mem = malloc(count * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}
