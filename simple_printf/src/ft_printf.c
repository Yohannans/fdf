/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:29:07 by yansquer          #+#    #+#             */
/*   Updated: 2024/12/01 12:29:36 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_identifiers(char id, va_list *p_args)
{
	int	out;

	if (id == 'c')
		out = print_char(p_args);
	else if (id == 's')
		out = print_str(p_args);
	else if (id == 'p')
		out = print_ptr(p_args);
	else if (id == 'i' || id == 'd')
		out = print_int(p_args);
	else if (id == 'u')
		out = print_uint(p_args);
	else if (id == 'x')
		out = print_hex_lc(p_args);
	else if (id == 'X')
		out = print_hex_uc(p_args);
	else if (id == '%')
	{
		out = 1;
		ft_putchar_fd('%', 1);
	}
	else
		out = 0;
	return (out);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			count++;
			i++;
		}
		else
		{
			count += print_identifiers(format[i + 1], &args);
			i += 2;
		}
	}
	return (count);
}
