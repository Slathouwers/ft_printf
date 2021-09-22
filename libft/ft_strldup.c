/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 10:26:30 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/22 10:38:49 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strldup(const char *s, size_t len)
{
	size_t	size;
	char	*dup;

	size = 0;
	if (!s)
		return (NULL);
	while (*s && len--)
		size++;
	dup = (char *) malloc(sizeof(char) * (size + 1));
	ft_memmove(dup, s, size);
	dup[size] = '\0';
	return (dup);
}
