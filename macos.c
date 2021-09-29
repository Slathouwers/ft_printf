/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:41:17 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/29 10:48:30 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	if(ft_printf("ft_printf: |%p|\n", NULL) == printf("___printf: |%p|\n", NULL))
		printf("OK");
}