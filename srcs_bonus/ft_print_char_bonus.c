/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:08:45 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/22 11:12:59 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	print_c(t_field *fld, t_format *fmt, va_list ap)
{
	if (*fld->parse_ptr == '%')
		ft_putchar_fd('%', 1);
	else
		ft_putchar_fd((char) va_arg(ap, int), 1);
	fmt->num_printed++;
}

static void	print_width(t_field *fld, t_format *fmt, char c)
{
	ft_putchar_fd(c, 1);
	fmt->num_printed++;
	fld->min_width--;
}

void	ft_print_char(t_field *fld, t_format *fmt, va_list ap)
{
	char	padding;

	if ((fld->zero_padding) && (*fld->parse_ptr == '%') && !(fld->left_align))
		padding = '0';
	else
		padding = ' ';
	if (fld->left_align)
		print_c(fld, fmt, ap);
	while (fld->min_width > 1)
		print_width(fld, fmt, padding);
	if (!fld->left_align)
		print_c(fld, fmt, ap);
	fmt->fstr = fld->parse_ptr + 1;
}
