/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:34:18 by yansquer          #+#    #+#             */
/*   Updated: 2024/11/07 10:34:20 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (dstsize == 0)
		return (ft_strlen((char *)src));
	j = 0;
	i = ft_strlen((char *)dst);
	while (i + j + 1 < dstsize && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i + j <= dstsize)
		dst[i + j] = '\0';
	if (i < dstsize)
		return (i + ft_strlen((char *)src));
	return (dstsize + ft_strlen((char *)src));
}
