/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:09:05 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/24 08:35:33 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void
	print_prefix_precision(t_field *fld, t_format *fmt, int len, char *str)
{
	if (*str != '0')
	{
		if (*fld->parse_ptr == 'p' || (fld->alt_form && *fld->parse_ptr == 'x'))
			fmt->num_printed += ft_putstrl_fd("0x", 2, 1);
		else if (fld->alt_form && *fld->parse_ptr == 'X')
			fmt->num_printed += ft_putstrl_fd("0X", 2, 1);
	}
	while (len-- > 0)
		fmt->num_printed += ft_putstrl_fd("0", 1, 1);
}

static void
	print_width(t_field *fld, t_format *fmt, char *str, int print_len)
{
	char	*padding;
	int		width_remainder;

	padding = " ";
	if (fld->zero_padding && fld->precision < 0 && !fld->left_align
		&& !fld->alt_form)
		padding = "0";
	width_remainder = fld->min_width;
	if (!(*str != '0' && !fld->precision))
	{
		if (*str != '(' && (*fld->parse_ptr == 'p' || fld->alt_form))
		{
			width_remainder -= 2;
			if (fld->precision > print_len + 2)
				width_remainder -= fld->precision;
			else
				width_remainder -= print_len;
		}
		else if (fld->precision > print_len)
			width_remainder -= fld->precision;
		else
			width_remainder -= print_len;
	}
	while (width_remainder-- > 0)
		fmt->num_printed += ft_putstrl_fd(padding, 1, 1);
}

static void
	print_h(t_field *fld, t_format *fmt, char *str)
{
	size_t	print_len;
	char	*hexstr;

	if (*fld->parse_ptr == 'p' && *str == '0')
		hexstr = "(nil)";
	else
		hexstr = str;
	print_len = ft_strlen(hexstr);
	if (!fld->left_align)
		print_width(fld, fmt, hexstr, print_len);
	if (*fld->parse_ptr == 'p' && *hexstr == '(')
		fmt->num_printed += ft_putstrl_fd("(nil)", 5, 1);
	else if (!(*hexstr == '0' && !fld->precision))
	{
		print_prefix_precision(fld, fmt, (fld->precision - print_len), hexstr);
		fmt->num_printed += ft_putstrl_fd(hexstr, print_len, 1);
	}
	if (fld->left_align)
		print_width(fld, fmt, hexstr, print_len);
}

void
	ft_print_hex(t_field *fld, t_format *fmt, va_list ap)
{
	char				*str;
	unsigned long int	ul;

	if (*fld->parse_ptr == 'x' || *fld->parse_ptr == 'X')
		ul = va_arg(ap, unsigned int);
	else
		ul = va_arg(ap, unsigned long int);
	if (*fld->parse_ptr == 'x' || *fld->parse_ptr == 'p' )
		str = ft_ultoa_base(ul, "0123456789abcdef");
	else
		str = ft_ultoa_base(ul, "0123456789ABCDEF");
	if (!str)
		return ;
	print_h(fld, fmt, str);
	fmt->fstr = fld->parse_ptr + 1;
	free(str);
}
