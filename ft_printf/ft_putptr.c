/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 08:03:58 by yel-bour          #+#    #+#             */
/*   Updated: 2026/11/14 14:16:53 by yel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long long	address;
	int					count;

	if (!ptr)
	{
		if (write(1, "(nil)", 5) != 5)
			return (-1);
		return (5);
	}
	address = (unsigned long long)ptr;
	if (write(1, "0x", 2) != 2)
		return (-1);
	count = ft_puthex(address, 'x');
	if (count < 0)
		return (-1);
	return (count + 2);
}
