/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:09:05 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/21 10:09:13 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
		fmt->num_printed += ft_putstrl_fd("(nil)", 5, 1);
	else if (*fmt->fstr == 'p')
		fmt->num_printed += ft_putstrl_fd("0x", 2, 1);
	if (!(*fmt->fstr == 'p' && print_len == 1 && *str == '0'))
		fmt->num_printed += ft_putstrl_fd(str, print_len, 1);
	fmt->fstr++;
	free(str);
}
