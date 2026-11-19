/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 08:32:02 by yel-bour          #+#    #+#             */
/*   Updated: 2026/10/22 14:16:35 by yel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;
	int		is_word;

	count = 0;
	i = 0;
	is_word = 1;
	while (s[i])
	{
		if (s[i] != c && is_word)
		{
			count++;
			is_word = 0;
		}
		else if (s[i] == c)
			is_word = 1;
		i++;
	}
	return (count);
}

static char	*get_word(char const *s, size_t start, size_t len)
{
	char	*word;
	size_t	i;

	word = malloc(len + 1);
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_words(char **result, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static int	fill_words(char **result, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] == c)
			j++;
		if (s[j] == '\0')
			break ;
		start = j;
		while (s[j] && s[j] != c)
			j++;
		result[i] = get_word(s, start, j - start);
		if (result[i] == NULL)
		{
			free_words(result, i);
			return (-1);
		}
		i++;
	}
	result[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	count;

	if (s == NULL)
		return (NULL);
	count = count_words(s, c);
	result = malloc((count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	if (fill_words(result, s, c) == -1)
		return (NULL);
	return (result);
}
