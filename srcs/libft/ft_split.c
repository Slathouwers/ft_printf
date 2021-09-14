/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 09:23:19 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/05 09:23:19 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char sep)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		while (*str && *str == sep)
			str++;
		if (*str && *str != sep)
		{
			count++;
			while (*str && *str != sep)
				str++;
		}
	}
	return (count);
}

static char	*get_word(char const *str, char sep)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	if (!word)
		return (NULL);
	while (str[i] && str[i] != sep)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_split(char **arr)
{
	if (arr)
	{
		if (*arr)
		{
			while (*arr)
				free(*arr++);
		}
		free(arr);
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	while (s && *s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			arr[i] = get_word(s, c);
			if (!arr[i++])
			{
				free_split(arr);
				return (NULL);
			}
			while (*s && *s != c)
				s++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
