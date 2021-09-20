/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:12:18 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/20 10:30:52 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_format
{
	const char	*fstr;
	int			num_printed;
}				t_format;

int		ft_printf(const char *format, ...);
void	ft_print_uint(t_format *fmt, va_list ap);
void	ft_print_int(t_format *fmt, va_list ap);
void	ft_print_hex(t_format *fmt, va_list ap);
void	ft_print_char(t_format *fmt, va_list ap);
void	ft_print_str(t_format *fmt, va_list ap);

#endif