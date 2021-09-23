/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_parse_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 08:29:07 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/23 11:17:05 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	update_width(t_field *fld)
{
	fld->min_width = ft_atoi(fld->parse_ptr);
	fld->parse_ptr += ft_nbr_len(fld->min_width);
}

static void	update_precision(t_field *fld)
{
	fld->parse_ptr++;
	if (ft_isdigit(*fld->parse_ptr))
	{
		while (ft_isdigit(*fld->parse_ptr))
		{
			fld->precision = ft_atoi(fld->parse_ptr);
			fld->parse_ptr += ft_nbr_len(fld->precision);
		}
	}
	else
		fld->precision = 0;
	if ((fld->precision >= 0) && (*fld->parse_ptr != '%'))
		fld->zero_padding = 0;
}

void	ft_field_parse(t_field *fld, char *pcnt_ptr)
{
	ft_bzero(fld, sizeof(*fld));
	fld->percent_ptr = pcnt_ptr;
	fld->parse_ptr = pcnt_ptr + 1;
	fld->precision = -1;
	while (ft_strchr("-0# +", *fld->parse_ptr))
	{
		if (*fld->parse_ptr == '-')
			fld->left_align = 1;
		if (*fld->parse_ptr == '0')
			fld->zero_padding = 1;
		if (*fld->parse_ptr == '#')
			fld->alt_form = 1;
		if (*fld->parse_ptr == ' ')
			fld->space = 1;
		if (*fld->parse_ptr == '+')
			fld->plus_sign = 1;
		fld->parse_ptr++;
	}
	if (ft_isdigit(*fld->parse_ptr))
		update_width(fld);
	if (*fld->parse_ptr == '.')
		update_precision(fld);
}
