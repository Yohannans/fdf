/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:19:14 by yansquer          #+#    #+#             */
/*   Updated: 2024/11/12 10:19:33 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*cpy;

	cpy = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		cpy[i] = (*f)(i, s[i]);
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
