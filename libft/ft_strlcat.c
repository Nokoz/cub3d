/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.42.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:00:01 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/11 17:52:05 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	int		k;

	if (!dst || !src || dstsize < 0)
		return (0);
	j = ft_strlen(dst);
	k = j;
	if (dstsize <= j)
		return (dstsize + ft_strlen(src));
	i = 0;
	while (src[i] && j + 1 < dstsize)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (k + ft_strlen(src));
}
