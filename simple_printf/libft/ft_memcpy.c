/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:28:50 by yansquer          #+#    #+#             */
/*   Updated: 2024/11/07 10:28:52 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*c_dst;

	if (!(dst || src))
		return (NULL);
	c_dst = (char *)dst;
	i = 0;
	while (i < n)
	{
		c_dst[i] = ((char *)src)[i];
		i++;
	}
	return ((void *)c_dst);
}
