/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:55:21 by yansquer          #+#    #+#             */
/*   Updated: 2024/11/27 18:33:31 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putnbr(long nbr, char *base, int len)
{
	int	i;

	i = 1;
	if (nbr >= (long)len)
		i += putnbr(nbr / len, base, len);
	ft_putchar_fd(base[nbr % len], 1);
	return (i);
}

int	print_int(va_list *p_args)
{
	int		i;
	long	nbr;

	nbr = (long)va_arg(*p_args, int);
	i = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		nbr *= -1;
		i++;
	}
	i += putnbr(nbr, "0123456789", 10);
	return (i);
}
