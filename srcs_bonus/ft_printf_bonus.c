/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:18:21 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/23 07:47:57 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_printl_nopercent(t_format *fmt, size_t len)
{
	len = ft_putstrl_fd(fmt->fstr, len, 1);
	fmt->num_printed += len;
	fmt->fstr += len;
}

static void	ft_print_parse(t_field *fld, t_format *fmt, va_list ap)
{
	if (*fld->parse_ptr == 'c' || *fld->parse_ptr == '%')
		ft_print_char(fld, fmt, ap);
	else if (*fld->parse_ptr == 's')
		ft_print_str(fld, fmt, ap);
	else if (*fld->parse_ptr == 'i' || *fld->parse_ptr == 'd'
		|| *fld->parse_ptr == 'u')
		ft_print_int(fld, fmt, ap);
	else if (*fld->parse_ptr == 'x' || *fld->parse_ptr == 'X'
		|| *fld->parse_ptr == 'p')
		ft_print_hex(fld, fmt, ap);
	else
	{
		ft_putchar_fd(*fld->percent_ptr, 1);
		fmt->fstr = fld->percent_ptr + 1;
		fmt->num_printed++;
	}
}

static void	ft_print(t_format *fmt, va_list ap)
{
	char		*pcnt_ptr;
	t_field		fld;

	pcnt_ptr = ft_strchr(fmt->fstr, '%');
	if (!pcnt_ptr)
		ft_printl_nopercent(fmt, ft_strlen(fmt->fstr));
	else
	{
		ft_printl_nopercent(fmt, (pcnt_ptr - fmt->fstr));
		ft_field_parse(&fld, pcnt_ptr);
		ft_print_parse(&fld, fmt, ap);
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
