/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 06:42:07 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/20 08:20:46 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	int		first;
	int		last;
	char	tmp;

	if (!str)
		return ;
	first = -1;
	last = ft_strlen(str);
	while (++first < --last)
	{
		tmp = str[first];
		str[first] = str[last];
		str[last] = tmp;
	}
}
