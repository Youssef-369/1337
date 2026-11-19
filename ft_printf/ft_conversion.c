/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:10:10 by yel-bour          #+#    #+#             */
/*   Updated: 2026/11/14 14:11:52 by yel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(char specifier, va_list *args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (specifier == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (specifier == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (specifier == 'u')
		return (ft_putunsigned(va_arg(*args, unsigned int)));
	if (specifier == 'x' || specifier == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), specifier));
	if (specifier == '%')
		return (ft_putchar('%'));
	return (-1);
}
