/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:43:36 by yansquer          #+#    #+#             */
/*   Updated: 2024/11/07 10:53:41 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	int		i;

	if (c % 128 == '\0')
		return ((char *)s + ft_strlen((char *)s));
	last = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c % 128)
			last = (char *)&s[i];
		i++;
	}
	return (last);
}
