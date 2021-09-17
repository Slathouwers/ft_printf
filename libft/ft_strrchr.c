/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:39:22 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/07 14:49:24 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*end;
	char		chr;

	chr = (char) c;
	if (!s)
		return (NULL);
	end = s;
	while (*end)
		end++;
	if (chr == '\0')
		return ((char *) end);
	while (--end >= s)
		if (chr == *end)
			return ((char *) end);
	return (NULL);
}
