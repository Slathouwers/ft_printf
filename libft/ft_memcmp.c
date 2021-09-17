/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:59:00 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/09 09:22:08 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	if (!s1 && !s2)
		return (0);
	p1 = (const unsigned char *) s1;
	p2 = (const unsigned char *) s2;
	if (!p1)
		return (0 - *p2);
	if (!p2)
		return (*p1);
	while (n-- > 0)
	{
		if (*p1++ != *p2++)
			return (*--p1 - *--p2);
	}
	return (0);
}
