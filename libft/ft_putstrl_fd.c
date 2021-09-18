/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:51:05 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/18 23:17:19 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstrl_fd(const char *s, size_t n, int fd)
{
	size_t	len;

	if (!s || fd < 0)
		return (0);
	len = ft_strlen(s);
	if (len < n)
		n = len;
	write(fd, s, n);
	return (n);
}
