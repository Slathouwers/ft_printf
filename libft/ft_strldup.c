/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 10:26:30 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/22 12:57:10 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strldup(const char *s, size_t len)
{
	size_t		size;
	const char	*s_start;
	char		*dup;

	size = 0;
	s_start = s;
	if (!s)
		return (NULL);
	while (*s++ && len--)
		size++;
	dup = (char *) malloc(sizeof(char) * (size + 1));
	ft_memmove(dup, s_start, size);
	dup[size] = '\0';
	return (dup);
}
