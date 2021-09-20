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

size_t	ft_ultobase_len(unsigned long int nbr, char *base)
{
	size_t	len;
	size_t	baselen;

	baselen = ft_strlen(base);
	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr && baselen > 0)
	{
		nbr /= baselen;
		len++;
	}
	return (len);
}

char	*ft_ultoa_base(unsigned long int n, char *base)
{
	size_t		baselen;
	size_t		len;
	char		*c;

	if (!base)
		return (NULL);
	len = ft_ultobase_len(n, base);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (0);
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len--] = '0' + base[(n % baselen)];
		n /= baselen;
	}
	return (c);
}
