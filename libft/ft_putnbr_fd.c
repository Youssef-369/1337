/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 18:41:37 by yel-bour          #+#    #+#             */
/*   Updated: 2026/10/18 09:46:40 by yel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		div;
	long	nb;
	char	result;

	div = 1;
	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	while (nb / div >= 10)
		div = div * 10;
	while (div > 0)
	{
		result = nb / div + '0';
		write(fd, &result, 1);
		nb = nb % div;
		div = div / 10;
	}
}
