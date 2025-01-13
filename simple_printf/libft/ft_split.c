/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:19:20 by yansquer          #+#    #+#             */
/*   Updated: 2024/11/12 10:20:35 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**cpy_things(char const *s, char c, char **out)
{
	char	*act;
	char	*next;
	int		i;

	act = (char *)s;
	while (*act && *act == c)
		act++;
	i = 0;
	while (*act)
	{
		next = ft_strchr(act, c);
		if (next == NULL)
			next = act + ft_strlen(act);
		out[i] = ft_substr(act, 0, next - act);
		if (!out[i])
			return (NULL);
		i++;
		act = next;
		while (*act && *act == c)
			act++;
	}
	out[i] = NULL;
	return (out);
}

char	**empty_str(void)
{
	char	**out;

	out = malloc(sizeof(char *));
	if (!out)
		return (NULL);
	*out = NULL;
	return (out);
}

char	**ft_split(char const *s, char c)
{
	size_t	n_str;
	size_t	i;
	char	**out;

	i = 0;
	if (!*s)
		return (empty_str());
	while (s[i] && s[i] == c)
		i++;
	n_str = 1;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c) && s[i + 1])
			n_str++;
		i++;
	}
	out = malloc(sizeof(char *) * (n_str + 1));
	if (!out)
		return (NULL);
	cpy_things(s, c, out);
	return (out);
}
