/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.42.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:11:03 by gvardaki          #+#    #+#             */
/*   Updated: 2023/04/11 11:56:30 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*p_dst;
	const char	*p_src;

	if (!dst && !src)
		return (0);
	p_dst = (char *)dst;
	p_src = (const char *) src;
	while (n--)
		*p_dst++ = *p_src++;
	return (dst);
}
