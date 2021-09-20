/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:27:27 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/20 10:28:33 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(t_format *fmt, va_list ap)
{
	if (*fmt->fstr == '%')
		ft_putchar_fd('%', 1);
	else
		ft_putchar_fd((char) va_arg(ap, int), 1);
	fmt->num_printed++;
	fmt->fstr++;
}
