/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:57:17 by yel-bour          #+#    #+#             */
/*   Updated: 2026/11/14 14:22:40 by yel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_recursive(long nb)
{
	int		count;
	char	c;

	count = 0;
	if (nb >= 10)
	{
		count = ft_putnbr_recursive(nb / 10);
		if (count < 0)
			return (-1);
	}
	c = (nb % 10) + '0';
	if (write(1, &c, 1) != 1)
		return (-1);
	return (count + 1);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		count;
	int		result;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		if (write(1, "-", 1) != 1)
			return (-1);
		count = 1;
		nb = -nb;
	}
	result = ft_putnbr_recursive(nb);
	if (result < 0)
		return (-1);
	return (count + result);
}
