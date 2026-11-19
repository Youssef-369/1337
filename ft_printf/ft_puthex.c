/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:53:18 by yel-bour          #+#    #+#             */
/*   Updated: 2026/11/14 14:23:57 by yel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long n, char format)
{
	int			count;
	const char	*hex;
	char		digit;

	count = 0;
	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		count = ft_puthex(n / 16, format);
		if (count < 0)
			return (-1);
	}
	digit = hex[n % 16];
	if (write(1, &digit, 1) != 1)
		return (-1);
	return (count + 1);
}
