/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:57:55 by yansquer          #+#    #+#             */
/*   Updated: 2024/11/07 12:03:56 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;

	if (!*needle)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	n_len = ft_strlen((char *)needle);
	i = 0;
	while (haystack[i] && len - n_len + 1 > i)
	{
		if (!ft_strncmp(&haystack[i], needle, n_len))
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
