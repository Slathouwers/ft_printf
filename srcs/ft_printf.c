/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:18:21 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/18 10:41:01 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_print(t_format *fmt, va_list ap)
{
	char		*pcnt_ptr;
//	char		*pre_str;
	(void) ap;
	pcnt_ptr = ft_strchr(fmt->fstr, '%');
	if (!pcnt_ptr)
	{
		ft_putstr_fd(fmt->fstr, 1);
		fmt->num_printed = ft_strlen(fmt->fstr);
		fmt->fstr += fmt->num_printed;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	fmt;

	va_start(ap, format);
	ft_bzero(&fmt, sizeof(t_format));
	fmt.precision = -1;
	fmt.fstr = format;
	while (fmt.fstr != format + ft_strlen(format))
		ft_print(&fmt, ap);
	va_end(ap);
	return (fmt.num_printed);
}
