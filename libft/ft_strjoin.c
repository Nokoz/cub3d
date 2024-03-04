/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:05:23 by gvardaki          #+#    #+#             */
/*   Updated: 2023/04/10 13:44:38 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		jlen;

	if (!s1 && !s2)
		return (0);
	jlen = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	join = malloc(sizeof (char) * jlen);
	if (!join)
		return (0);
	ft_strlcpy(join, s1, jlen);
	ft_strlcat(join, s2, jlen);
	join[jlen - 1] = '\0';
	return (join);
}
