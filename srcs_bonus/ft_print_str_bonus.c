/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:30:19 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/22 12:41:35 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	print_padding(size_t len)
{
	while (len--)
		ft_putchar_fd(' ', 1);
}

static void	print_s(t_field *fld, t_format *fmt, char *str)
{
	size_t	padding;

	padding = 0;
	if ((size_t)fld->min_width > ft_strlen(str))
		padding = fld->min_width - ft_strlen(str);
	if (fld->left_align)
		fmt->num_printed += ft_putstrl_fd(str, ft_strlen(str), 1);
	print_padding(padding);
	fmt->num_printed += padding;
	if (!fld->left_align)
		fmt->num_printed += ft_putstrl_fd(str, ft_strlen(str), 1);
}

void	ft_print_str(t_field *fld, t_format *fmt, va_list ap)
{
	char	*str;
	char	*trunc;
	int		len;

	str = va_arg(ap, char *);
	if (fld->precision > -1)
		len = fld->precision;
	else
		len = ft_strlen(str);
	trunc = ft_strldup(str, len);
	if (!str)
		fmt->num_printed += ft_putstrl_fd("(null)", 6, 1);
	else
		print_s(fld, fmt, trunc);
	free(trunc);
	fmt->fstr = fld->parse_ptr + 1;
}
