/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:21:45 by yansquer          #+#    #+#             */
/*   Updated: 2024/12/01 09:00:21 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putnbr(uintptr_t nbr, char *base, int len)
{
	int	i;

	i = 1;
	if (nbr >= (uintptr_t)len)
		i += putnbr(nbr / len, base, len);
	ft_putchar_fd(base[nbr % len], 1);
	return (i);
}

int	print_ptr(va_list *p_args)
{
	int			i;
	uintptr_t	nbr;

	nbr = (uintptr_t)va_arg(*p_args, void *);
	if (nbr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	i = 2;
	i += putnbr(nbr, "0123456789abcdef", 16);
	return (i);
}
