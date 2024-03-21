/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:08:37 by salowie           #+#    #+#             */
/*   Updated: 2024/03/21 14:23:53 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/cub3d.h"

static int	is_sep(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	nbr_words(char const *s, char c)
{
	int	nbr;
	int	i;

	nbr = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (!is_sep(s[i], c))
			nbr++;
		while (!is_sep(s[i], c) && s[i])
			i++;
		while (is_sep(s[i], c) && s[i])
			i++;
	}
	return (nbr);
}

static int	word_lenght(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (!is_sep(s[i], c) && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static char	**ft_free_d(char **newstr)
{
	int	i;

	i = 0;
	while (newstr[i])
	{
		free(newstr[i]);
		i++;
	}
	free(newstr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**newstr;
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	newstr = malloc(sizeof(char *) * (nbr_words(s, c) + 1));
	if (!newstr)
		return (NULL);
	while (s[i[0]])
	{
		if (!is_sep(s[i[0]], c))
		{
			newstr[i[1]++] = ft_substr(s, i[0], word_lenght(s, c, i[0]));
			if (!newstr[i[1] -1])
				return (ft_free_d(newstr));
		}
		while (!is_sep(s[i[0]], c) && s[i[0]])
			i[0]++;
		while (is_sep(s[i[0]], c) && s[i[0]])
			i[0]++;
	}
	newstr[i[1]] = 0;
	return (newstr);
}
