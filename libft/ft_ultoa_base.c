/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 08:19:35 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/20 08:19:35 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa_base(unsigned long long int n, char *base)
{
	size_t		baselen;
	size_t		len;
	char		*c;

	if (!base)
		return (NULL);
	baselen = ft_strlen(base);
	len = ft_ultobase_len(n, base);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (0);
	c[len] = '\0';
	len--;
	while (len > 0)
	{
		c[len--] = base[(n % baselen)];
		n /= baselen;
	}
	c[len] = base[(n % baselen)];
	return (c);
}
