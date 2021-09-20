/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_bse_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 09:23:40 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/05 09:23:40 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlong_base_fd(long int n, char *base, int fd)
{
	unsigned long int	un;
	size_t				baselen;

	if (!base)
		return ;
	if (fd < 0)
		return ;
	baselen = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		un = (unsigned long int) -n;
	}
	else
		un = (unsigned long int) n;
	if (un > baselen)
		ft_putlong_base_fd(un / baselen, base, fd);
	ft_putchar_fd(base[(un % baselen)], fd);
}
