/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:28:05 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/09 09:28:03 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (!haystack)
		return (NULL);
	if (!needle_len)
		return ((char *) haystack);
	while (len-- >= needle_len)
	{
		if (!*haystack)
			break ;
		if (!ft_strncmp(haystack, needle, needle_len))
			return ((char *) haystack);
		haystack++;
	}
	return (NULL);
}
