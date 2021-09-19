/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:41:02 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/19 16:03:04 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int n = -2147483648;
	unsigned int un = 4294967295;

	char *strun = ft_uitoa(un);
	//printf("%.10bd",10);
	printf("%i\n",ft_printf("%%%s%i%u","Sander", 50, un));
	printf("len of n = %lu", ft_nbr_len(n));
	printf("len of un = %lu", ft_unbr_len(un));
	printf("\nun = %s\n", strun);
	ft_putunbr_fd(un, 1);
	ft_putchar_fd('\n', 1);
	free(strun);
	return (0);
}
