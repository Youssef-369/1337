/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:21:04 by yel-bour          #+#    #+#             */
/*   Updated: 2026/11/14 14:17:22 by yel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int		count;
	char	digit;

	count = 0;
	if (n >= 10)
	{
		count = ft_putunsigned(n / 10);
		if (count < 0)
			return (-1);
	}
	digit = (n % 10) + '0';
	if (write(1, &digit, 1) != 1)
		return (-1);
	return (count + 1);
}
