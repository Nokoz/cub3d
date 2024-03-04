/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:10:51 by gvardaki          #+#    #+#             */
/*   Updated: 2023/04/11 16:49:04 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*t;
	int		i;
	int		j;
	int		k;

	if (!s1 || !set)
		return (0);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strrchr(set, s1[i]))
		i++;
	while (j > i && ft_strrchr(set, s1[j - 1]))
		j--;
	t = malloc(j - i + 1);
	if (!t)
		return (0);
	k = 0;
	while (i < j)
		t[k++] = s1[i++];
	t[k] = '\0';
	return (t);
}
