/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 17:00:04 by yel-bour          #+#    #+#             */
/*   Updated: 2026/10/18 09:41:45 by yel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	c_v1;
	char			*str;

	str = (char *)s;
	c_v1 = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == c_v1)
			return (&str[i]);
		i++;
	}
	if (c_v1 == '\0')
		return (&str[i]);
	return (NULL);
}
