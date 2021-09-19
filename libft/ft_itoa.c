/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 09:24:04 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/05 09:24:04 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	to_un(int n, int *sign)
{
	unsigned int	un;

	if (n < 0)
	{
		*sign = -1;
		un = (unsigned int) - n;
	}
	else
		un = n;
	return (un);
}

char	*ft_itoa(int n)
{
	int				len;
	int				sign;
	char			*c;
	unsigned int	un;

	sign = 0;
	un = to_un(n, &sign);
	len = ft_nbr_len(n);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (0);
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len--] = '0' + (un % 10);
		un /= 10;
	}
	if (sign == -1)
		c[0] = '-';
	return (c);
}
