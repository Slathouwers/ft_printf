/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultobase_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 08:31:07 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/24 06:28:42 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ultobase_len(unsigned long long int nbr, char *base)
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
