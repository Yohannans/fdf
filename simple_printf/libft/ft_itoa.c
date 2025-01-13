/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:46:25 by yansquer          #+#    #+#             */
/*   Updated: 2024/11/12 10:18:50 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_log10(long n)
{
	int	log;

	log = 0;
	while (n >= 10)
	{
		n /= 10;
		log++;
	}
	return (log + 1);
}

static int	recur(char *str, long n)
{
	int	index;

	if (n >= 10)
		index = recur(str, n / 10);
	else
		index = 0;
	str[index] = '0' + n % 10;
	return (index + 1);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	if (n < 0)
		len = n_log10(-(long)n) + 1;
	else
		len = n_log10(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		recur(&str[1], -(long)n);
	}
	else
		recur(str, n);
	str[len] = '\0';
	return (str);
}
