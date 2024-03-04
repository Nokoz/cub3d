/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:36:54 by gvardaki          #+#    #+#             */
/*   Updated: 2023/04/17 15:51:48 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_split_size(char const *s, char c)
{
	int	j;

	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			j++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (j);
}

static char	**ft_free(char **tab, size_t i)
{
	while (i--)
		free(tab[i]);
	free(tab);
	return (0);
}

static char	**ft_fill_tab(char **tab, char const *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c)
			{
				len++;
				s++;
			}
			tab[i] = ft_substr(s - len, 0, len);
			if (!tab[i])
				return (ft_free(tab, i));
			i++;
		}
		else
			s++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		size;

	if (!s)
		return (0);
	size = ft_split_size(s, c) + 1;
	split = malloc(sizeof (char *) * size);
	if (!split)
	{
		return (0);
	}
	split = ft_fill_tab(split, s, c);
	if (!split)
	{
		return (0);
	}
	split[size - 1] = 0;
	return (split);
}
