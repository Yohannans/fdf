/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:25:55 by yansquer          #+#    #+#             */
/*   Updated: 2024/12/05 09:25:49 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	print_char(va_list *p_args);
int	print_str(va_list *p_args);
int	print_ptr(va_list *p_args);
int	print_int(va_list *p_args);
int	print_uint(va_list *p_args);
int	print_hex_lc(va_list *p_args);
int	print_hex_uc(va_list *p_args);

#endif
