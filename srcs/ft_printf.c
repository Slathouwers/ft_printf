/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:18:21 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/19 16:01:08 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_print_fmt_len(t_format *fmt, size_t len)
{
	size_t		print_len;

	print_len = ft_putstrl_fd(fmt->fstr, len, 1);
	fmt->num_printed += print_len;
	fmt->fstr += print_len;
}

void	ft_print_char(t_format *fmt, va_list ap)
{
	if (*fmt->fstr == '%')
		ft_putchar_fd('%', 1);
	else
		ft_putchar_fd((char) va_arg(ap, int), 1);
	fmt->num_printed++;
	fmt->fstr++;
}

void	ft_print_str(t_format *fmt, va_list ap)
{
	char	*str;
	size_t	print_len;

	str = va_arg(ap, char *);
	print_len = ft_strlen(str);
	ft_putstrl_fd(str, print_len, 1);
	fmt->num_printed += print_len;
	fmt->fstr++;
}

void	ft_print_int(t_format *fmt, va_list ap)
{
	char	*str;
	int		i;
	size_t	print_len;

	i = va_arg(ap, int);
	str = ft_itoa(i);
	print_len = ft_nbr_len(i);
	ft_putstrl_fd(str, print_len, 1);
	fmt->num_printed += print_len;
	fmt->fstr++;
	free(str);
}

void	ft_print_uint(t_format *fmt, va_list ap)
{
	char			*str;
	unsigned int	ui;
	size_t			print_len;

	ui = va_arg(ap, unsigned int);
	str = ft_uitoa(ui);
	print_len = ft_unbr_len(ui);
	ft_putstrl_fd(str, print_len, 1);
	fmt->num_printed += print_len;
	fmt->fstr++;
	free(str);
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
}

static void	ft_print(t_format *fmt, va_list ap)
{
	char		*pcnt_ptr;

	pcnt_ptr = ft_strchr(fmt->fstr, '%');
	if (!pcnt_ptr)
		ft_print_fmt_len(fmt, ft_strlen(fmt->fstr));
	else
	{
		ft_print_fmt_len(fmt, (pcnt_ptr - fmt->fstr));
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
	fmt.precision = -1;
	fmt.fstr = format;
	while (fmt.fstr < format + ft_strlen(format))
		ft_print(&fmt, ap);
	va_end(ap);
	return (fmt.num_printed);
}
