/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:09:05 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/29 12:08:26 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void
	print_prefix_precision(t_field *fld, t_format *fmt, int len, char *str)
{
	if (*fld->parse_ptr == 'p')
		fmt->num_printed += ft_putstrl_fd("0x", 2, 1);
	else if (*str != '0')
	{
		if (fld->alt_form && *fld->parse_ptr == 'x')
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
	if (*fld->parse_ptr == 'p' || (*str != '0' && fld->alt_form))
		width_remainder -= 2;
	if (!(*str == '0' && fld->precision == 0))
		width_remainder -= ft_max(fld->precision, print_len);
	while (width_remainder-- > 0)
		fmt->num_printed += ft_putstrl_fd(padding, 1, 1);
}

static void
	print_h(t_field *fld, t_format *fmt, char *str)
{
	size_t	print_len;
	char	*hexstr;

	hexstr = str;
	print_len = ft_strlen(hexstr);
	if (!fld->left_align)
		print_width(fld, fmt, hexstr, print_len);
	print_prefix_precision(fld, fmt, (fld->precision - print_len), hexstr);
	if (!(*hexstr == '0' && fld->precision == 0))
	{
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
