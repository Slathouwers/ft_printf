/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:41:02 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/22 08:11:46 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int n = -2147483648;
	unsigned int un = 4294967295;
	char str[] = "0123456789ABCDEF";

	/* -------------- Unsigned int*/
	/* char *strun = ft_uitoa(un);
	//printf("%.10bd",10);
	printf("%i\n",ft_printf("%%%s%i%u","Sander", 50, un));
	printf("len of n = %lu", ft_nbr_len(n));
	printf("len of un = %lu", ft_unbr_len(un));
	printf("\nun = %s\n", strun);
	ft_putunbr_fd(un, 1);
	ft_putchar_fd('\n', 1);
	free(strun); */
	
	/*-----------HEX-------*/
	/* ft_strrev(str);
	printf("%s", str); */
	//ft_putlong_base_fd(9223372036854775807, "0123456789ABCDEF", 1);
	printf("x = %x\n X = %X\n", -1, -1);
	//printf("\n%s\n",ft_ultoa_base((unsigned int)-1, str));
	printf("---------x-------\n");
	printf("x = %x\n", un);
	ft_printf("x = %x\n", un);
	printf("---------X-------\n");
	printf("X = %X\n", un);
	ft_printf("X = %X\n", un);
	printf("---------pointer-------\n");
	printf("p = %#p\n", &un);
	ft_printf("p = %p\n", &un);
	/*---- STRING ERROR -------*/
/* 	if(ft_printf("NULL %s NULL\n", NULL) == printf("NULL %s NULL\n", NULL))
		printf("OK\n"); */
	return (0);
}
