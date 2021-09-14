/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:00:13 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/09 09:09:32 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*src_ptr;
	char		*dst_ptr;

	if (!dst || !src || !len)
		return (dst);
	if (dst < src)
	{
		src_ptr = (const char *) src;
		dst_ptr = (char *) dst;
		while (len--)
			*dst_ptr++ = *src_ptr++;
	}
	else
	{
		src_ptr = (const char *) src + len - 1;
		dst_ptr = (char *) dst + len - 1;
		while (len--)
			*dst_ptr-- = *src_ptr--;
	}
	return (dst);
}
