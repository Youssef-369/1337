/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:26:00 by yel-bour          #+#    #+#             */
/*   Updated: 2026/10/30 07:41:14 by yel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(long nb)
{
	size_t	count;

	count = 0;
	while (nb > 0)
	{
		count++;
		nb = nb / 10;
	}
	if (count == 0)
		count = 1;
	return (count);
}

static void	fill_digits(char *result, long nb, size_t digits,
	size_t negative)
{
	size_t	i;

	i = 0;
	while (i < digits)
	{
		result[digits + negative - 1 - i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	result[digits + negative] = '\0';
}

char	*ft_itoa(int n)
{
	char	*result;
	long	nb;
	size_t	negative;
	size_t	digits;

	negative = 0;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		negative = 1;
	}
	digits = count_digits(nb);
	result = malloc(digits + negative + 1);
	if (result == NULL)
		return (NULL);
	if (negative == 1)
		result[0] = '-';
	fill_digits(result, nb, digits, negative);
	return (result);
}
