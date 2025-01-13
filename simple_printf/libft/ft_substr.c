/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:03:04 by yansquer          #+#    #+#             */
/*   Updated: 2024/11/07 14:20:19 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	max;
	unsigned int	i;
	char			*cpy;

	if (start > ft_strlen((char *)s))
		return (ft_strdup(""));
	max = ft_strlen((char *)&s[start]);
	if (max > len)
		cpy = malloc(sizeof(char) * (len + 1));
	else
		cpy = malloc(sizeof(char) * (max + 1));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		cpy[i] = s[start + i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
