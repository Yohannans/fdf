/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:25:38 by yansquer          #+#    #+#             */
/*   Updated: 2024/11/27 18:32:36 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putnbr(unsigned int nbr, char *base, int len)
{
	int	i;

	i = 1;
	if (nbr >= (unsigned int)len)
		i += putnbr(nbr / len, base, len);
	ft_putchar_fd(base[nbr % len], 1);
	return (i);
}

int	print_hex_lc(va_list *p_args)
{
	int				i;
	unsigned int	nbr;

	nbr = va_arg(*p_args, unsigned int);
	i = putnbr(nbr, "0123456789abcdef", 16);
	return (i);
}
