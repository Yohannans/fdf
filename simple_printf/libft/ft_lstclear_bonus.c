/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:53:31 by yansquer          #+#    #+#             */
/*   Updated: 2024/11/13 19:28:55 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*next_ptr;

	ptr = *lst;
	*lst = NULL;
	while (ptr)
	{
		next_ptr = ptr->next;
		(*del)(ptr->content);
		free(ptr);
		ptr = next_ptr;
	}
}
