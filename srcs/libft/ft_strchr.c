/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:30:08 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/09 08:24:26 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	if (!s)
		return (NULL);
	chr = (char) c;
	while (*s != chr)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)(s));
}
