/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:18:15 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/29 10:57:52 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (*fmt->fstr == 'p')
		fmt->num_printed += ft_putstrl_fd("0x", 2, 1);
	fmt->num_printed += ft_putstrl_fd(str, print_len, 1);
	fmt->fstr++;
	free(str);
}
