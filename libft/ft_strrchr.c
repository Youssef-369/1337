/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 07:27:23 by yel-bour          #+#    #+#             */
/*   Updated: 2026/10/18 09:39:28 by yel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*result;
	char			*str;
	unsigned char	c_v1;
	int				i;

	str = (char *)s;
	c_v1 = (unsigned char)c;
	result = NULL;
	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == c_v1)
			result = &str[i];
		i++;
	}
	if (c_v1 == '\0')
		result = &str[i];
	return (result);
}
