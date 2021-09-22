/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:18:21 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/22 07:22:49 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printl_nopercent(t_format *fmt, size_t len)
{
	len = ft_putstrl_fd(fmt->fstr, len, 1);
	fmt->num_printed += len;
	fmt->fstr += len;
}

void	ft_print_parse(t_format *fmt, va_list ap)
{
	if (*fmt->fstr == 'c' || *fmt->fstr == '%')
		ft_print_char(fmt, ap);
	else if (*fmt->fstr == 's')
		ft_print_str(fmt, ap);
	else if (*fmt->fstr == 'i' || *fmt->fstr == 'd')
		ft_print_int(fmt, ap);
	else if (*fmt->fstr == 'u')
		ft_print_uint(fmt, ap);
	else if (*fmt->fstr == 'x' || *fmt->fstr == 'X' || *fmt->fstr == 'p')
		ft_print_hex(fmt, ap);
}

static void	ft_print(t_format *fmt, va_list ap)
{
	char		*pcnt_ptr;

	pcnt_ptr = ft_strchr(fmt->fstr, '%');
	if (!pcnt_ptr)
		ft_printl_nopercent(fmt, ft_strlen(fmt->fstr));
	else
	{
		ft_printl_nopercent(fmt, (pcnt_ptr - fmt->fstr));
		fmt->fstr++;
		ft_print_parse(fmt, ap);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	fmt;

	va_start(ap, format);
	ft_bzero(&fmt, sizeof(t_format));
	fmt.fstr = format;
	while (fmt.fstr < format + ft_strlen(format))
		ft_print(&fmt, ap);
	va_end(ap);
	return (fmt.num_printed);
}
