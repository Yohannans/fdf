/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:40:13 by yansquer          #+#    #+#             */
/*   Updated: 2024/11/19 12:08:03 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*us;

	us = (unsigned char *)s;
	i = 0;
	while (us[i] && us[i] != c % 128)
		i++;
	if (!us[i] && c % 128)
		return (NULL);
	return ((char *)us + i);
}
