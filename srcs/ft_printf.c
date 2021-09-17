/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:18:21 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/17 11:42:55 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*s;
	char	c;
	int		i;

	va_start(ap, format);
	while (*format)
	{
		if (*format == 's')
		{
			s = va_arg(ap, char *);
			ft_putendl_fd(s, 1);
		}
		if (*format == 'i')
		{
			i = va_arg(ap, int);
			ft_putnbr_fd(i, 1);
			ft_putchar_fd('\n', 1);
		}
		if (*format == 'c')
		{
			c = va_arg(ap, int);
			ft_putchar_fd((char)c, 1);
			ft_putchar_fd('\n', 1);
		}
		format++;
	}
	va_end(ap);
	return (0);
}
