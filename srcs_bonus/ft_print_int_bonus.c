/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:09:22 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/23 10:51:07 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void
	print_sign(t_format *fmt, char sign)
{	
	if (sign)
	{
		ft_putchar_fd(sign, 1);
		fmt->num_printed ++;
	}
}

static void
	print_precise_n(t_field *fld, t_format *fmt, unsigned int n)
{
	char	*str;
	int		len;

	str = ft_uitoa(n);
	if (!str)
		return ;
	len = fld->precision - ft_strlen(str);
	while (len -- > 0)
	{
		ft_putchar_fd('0', 1);
		fmt->num_printed++;
	}
	if (!(!n && !fld->precision))
		fmt->num_printed += ft_putstrl_fd(str, ft_strlen(str), 1);
	free(str);
}

static void
	print_width(t_field *fld, t_format *fmt, char sign, unsigned int n)
{
	int		width_remainder;
	char	padding;
	int		num_len;

	padding = ' ';
	if (fld->zero_padding && fld->precision < 0 && !fld->left_align)
		padding = '0';
	num_len = ft_unbr_len(n);
	width_remainder = fld->min_width;
	if (sign)
		width_remainder--;
	if (fld->precision > num_len)
		width_remainder -= fld->precision;
	else if (!(!fld->precision && !n))
		width_remainder -= num_len;
	while (width_remainder-- > 0)
	{
		ft_putchar_fd(padding, 1);
		fmt->num_printed++;
	}
}

static void
	print_n(t_field *fld, t_format *fmt, unsigned int n, char sign)
{
	if (fld->left_align)
	{
		print_sign(fmt, sign);
		print_precise_n(fld, fmt, n);
		print_width(fld, fmt, sign, n);
	}
	else
	{
		if (fld->precision && fld->zero_padding)
			print_sign(fmt, sign);
		print_width(fld, fmt, sign, n);
		if (!fld->precision || !fld->zero_padding)
			print_sign(fmt, sign);
		print_precise_n(fld, fmt, n);
	}
}

void
	ft_print_int(t_field *fld, t_format *fmt, va_list ap)
{
	long int	i;
	char		sign;

	sign = '\0';
	if (*fld->parse_ptr == 'd' || *fld->parse_ptr == 'i')
	{
		i = va_arg(ap, int);
		if (i >= 0 && fld->plus_sign)
			sign = '+';
		else if (i >= 0 && fld->space)
			sign = ' ';
		if (i < 0)
		{
			sign = '-';
			i *= -1;
		}
	}
	else
		i = va_arg(ap, unsigned int);
	print_n(fld, fmt, i, sign);
	fmt->fstr = fld->parse_ptr + 1;
}
