/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:45:25 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/09 08:52:51 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dst;
	unsigned char	val;

	if (!b)
		return (NULL);
	dst = (unsigned char *) b;
	val = (unsigned char) c;
	while (len-- > 0)
		*dst++ = val;
	return (b);
}
