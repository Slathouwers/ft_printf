/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 09:03:03 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/05 09:03:03 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	subs_len;

	if (!s)
		return (NULL);
	if ((size_t) start > ft_strlen(s))
		return (ft_strdup(""));
	subs_len = ft_strlen(s + start);
	if (len < subs_len)
		subs_len = len;
	subs = malloc(sizeof(char) * (subs_len + 1));
	if (!subs)
		return (0);
	ft_strlcpy(subs, s + start, subs_len + 1);
	return (subs);
}
