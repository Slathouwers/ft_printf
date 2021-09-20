/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:30:19 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/20 10:30:42 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
