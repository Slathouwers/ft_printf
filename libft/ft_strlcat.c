/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 09:20:26 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/05 09:20:26 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	cpy_len;

	if (!dst)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (!src)
		return (dst_len);
	if (dst_len >= size)
		return (size + src_len);
	dst += dst_len;
	size -= dst_len;
	if (src_len >= size)
		cpy_len = size - 1;
	else
		cpy_len = src_len;
	ft_memcpy(dst, src, cpy_len);
	*(dst + cpy_len) = 0;
	return (dst_len + src_len);
}
