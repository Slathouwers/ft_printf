/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 09:23:40 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/05 09:23:40 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (fd < 0)
		return ;
	if (n > 9)
		ft_putunbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}
