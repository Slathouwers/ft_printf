/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:12:18 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/18 10:36:33 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_format
{
	const char	*fstr;
	int			num_printed;
	int			left_align;
	int			zero;
	int			min_width;
	int			precision;
}				t_format;

int	ft_printf(const char *format, ...);

#endif