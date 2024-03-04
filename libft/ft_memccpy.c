/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.42.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 09:28:01 by gvardaki          #+#    #+#             */
/*   Updated: 2023/04/03 21:16:01 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
int c, size_t n)
{
	char		*p_dst;
	const char	*p_src;
	int			i;

	p_dst = (char *)dst;
	p_src = (const char *) src;
	i = 0;
	while (n--)
	{
		p_dst[i] = p_src[i];
		if (p_src[i] == (unsigned char) c)
			return (p_dst + i + 1);
		i++;
	}
	return (0);
}
