/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:25:32 by gvardaki          #+#    #+#             */
/*   Updated: 2023/04/12 09:53:54 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	slen;
	size_t	end;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	end = 0;
	if (start > slen)
		start = slen;
	if (start < slen)
		end = slen - start;
	if (end > len)
		end = len;
	p = malloc(end + 1);
	if (!p)
		return (0);
	ft_strlcpy(p, (s + start), end + 1);
	return (p);
}
