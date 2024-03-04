/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.42.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:38:22 by gvardaki          #+#    #+#             */
/*   Updated: 2023/04/11 16:05:06 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;

	nlen = ft_strlen(needle);
	if (((int)len == -1 && ft_strlen(haystack) == 0 && nlen != 0) || len < 0)
		return (0);
	if (nlen == 0)
		return ((char *)haystack);
	while (len-- >= nlen)
	{
		if (!ft_memcmp(haystack, needle, nlen))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
