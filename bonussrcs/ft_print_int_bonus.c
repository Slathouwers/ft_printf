/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:09:22 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/21 10:09:31 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
