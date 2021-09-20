/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:18:21 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/20 10:10:16 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_printl_fmt(t_format *fmt, size_t len)
{
	len = ft_putstrl_fd(fmt->fstr, len, 1);
	fmt->num_printed += len;
	fmt->fstr += len;
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
	
	str = va_arg(ap, char *);
	if (!str)
		fmt->num_printed += ft_putstrl_fd("(null)", 6, 1);
	else
		fmt->num_printed += ft_putstrl_fd(str, ft_strlen(str), 1);
	fmt->fstr++;
}

void	ft_print_int(t_format *fmt, va_list ap)
{
	char	*str;
	int		i;
	size_t	print_len;

	i = va_arg(ap, int);
	str = ft_itoa(i);
	if (!str)
		return ;
	print_len = ft_nbr_len(i);
	fmt->num_printed += ft_putstrl_fd(str, print_len, 1);
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
	if (!str)
		return ;
	print_len = ft_unbr_len(ui);
	fmt->num_printed += ft_putstrl_fd(str, print_len, 1);
	fmt->fstr++;
	free(str);
}

void	ft_print_hex(t_format *fmt, va_list ap)
{
	char			*str;
	unsigned long	ul;
	size_t			print_len;

	if (*fmt->fstr == 'x' || *fmt->fstr == 'X')
		ul = va_arg(ap, unsigned int);
	else
		ul = va_arg(ap, unsigned long int);
	if (*fmt->fstr == 'x' || *fmt->fstr == 'p' )
		str = ft_ultoa_base(ul, "0123456789abcdef");
	else
		str = ft_ultoa_base(ul, "0123456789ABCDEF");
	if (!str)
		return ;
	print_len = ft_ultobase_len(ul, "0123456789ABCDEF");
	if (*fmt->fstr == 'p' && print_len == 1 && *str == '0')
	{
		fmt->num_printed += ft_putstrl_fd("(nil)", 5, 1);
		fmt->fstr++;
		free(str);
		return ;
	}
	if (*fmt->fstr == 'p')
		fmt->num_printed += ft_putstrl_fd("0x", 2, 1);
	fmt->num_printed += ft_putstrl_fd(str, print_len, 1);
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
	else if (*fmt->fstr == 'x' || *fmt->fstr == 'X' || *fmt->fstr == 'p')
		ft_print_hex(fmt, ap);
}

static void	ft_print(t_format *fmt, va_list ap)
{
	char		*pcnt_ptr;

	pcnt_ptr = ft_strchr(fmt->fstr, '%');
	if (!pcnt_ptr)
		ft_printl_fmt(fmt, ft_strlen(fmt->fstr));
	else
	{
		ft_printl_fmt(fmt, (pcnt_ptr - fmt->fstr));
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
