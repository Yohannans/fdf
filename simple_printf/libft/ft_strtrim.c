/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:24:43 by yansquer          #+#    #+#             */
/*   Updated: 2024/11/19 12:01:58 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (checkset(s1[i], set))
		i++;
	j = ft_strlen((char *)s1) - 1;
	while (checkset(s1[j], set) && j > 0)
		j--;
	if (j < i)
		return (ft_strdup(""));
	return (ft_substr(s1, i, (j - i) + 1));
}
