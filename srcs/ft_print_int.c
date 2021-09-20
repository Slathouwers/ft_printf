/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:24:32 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/20 10:24:53 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_int(t_format *fmt, va_list ap)
{
	char	*str;
	int		i;
	size_t	print_len;

	i = va_arg(ap, int);
	str = ft_itoa(i);
	if (!str)
		return ;
	print_len = ft_nbr_len(i);
	fmt->num_printed += ft_putstrl_fd(str, print_len, 1);
	fmt->fstr++;
	free(str);
}
