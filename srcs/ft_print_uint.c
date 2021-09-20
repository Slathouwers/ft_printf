/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:22:59 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/20 10:23:23 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
