/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 06:48:40 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/23 07:21:55 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	main(void)
{
	int d = 123;
	//ft_printf("ft_printf: |%c|\n", 'x');
	printf("___printf: |%+ 10.5d|\n", d);
	//ft_printf("ft_printf: |%3c|\n", 'x');
	printf("___printf: |%+ 5.2d|\n", d);
	printf("___printf: |%+ 3.5d|\n", d);
	printf("___printf: |%+ 4.4d|\n", d);
	printf("___printf: |%+ 4d|\n", d);
	return (0);
}
