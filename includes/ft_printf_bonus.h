/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:12:18 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/22 12:48:59 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_format
{
	const char	*fstr;
	int			num_printed;
}				t_format;

typedef struct s_field
{
	char		*percent_ptr;
	char		*parse_ptr;
	size_t		length;
	int			left_align;
	int			zero_padding;
	int			min_width;
	int			precision;
	int			alt_form;
	int			space;
	int			plus_sign;
}				t_field;

int		ft_printf(const char *format, ...);
void	ft_print_uint(t_field *fld, t_format *fmt, va_list ap);
void	ft_print_int(t_field *fld, t_format *fmt, va_list ap);
void	ft_print_hex(t_field *fld, t_format *fmt, va_list ap);
void	ft_print_char(t_field *fld, t_format *fmt, va_list ap);
void	ft_print_str(t_field *fld, t_format *fmt, va_list ap);
void	ft_field_parse(t_field *fld, char *pcnt_ptr);
#endif