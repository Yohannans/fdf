/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:22:09 by yansquer          #+#    #+#             */
/*   Updated: 2024/11/07 14:22:11 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*jn;

	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	jn = malloc(sizeof(char) * (len1 + len2 + 1));
	if (jn == NULL)
		return (NULL);
	ft_strlcpy(jn, s1, len1 + 1);
	ft_strlcpy(jn + len1, s2, len2 + 1);
	return (jn);
}
