/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:47:21 by salowie           #+#    #+#             */
/*   Updated: 2024/03/25 16:11:14 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/cub3d.h"

void	error_exit(char *str)
{
	printf("%s", str);
	exit (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				c;
	unsigned const char	*str1;
	unsigned const char	*str2;

	c = 0;
	str1 = (unsigned const char *)s1;
	str2 = (unsigned const char *)s2;
	if (n == 0)
		return (0);
	while (str1[c] == str2[c] && str1[c] && str2[c] && --n)
		c++;
	return (str1[c] - str2[c]);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strlen_double_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

char	*ft_strdup_no_tab(char *s1, int i, int j, int x)
{
	char	*str;
	int		tab;

	tab = nbr_tab(s1);
	str = malloc(sizeof(char) * (ft_strlen(s1) + 1 + (tab * 4) - tab));
	if (!str || !s1)
		return (NULL);
	while (s1[i])
	{
		if (s1[i] == '\t')
		{
			while (x < 4)
			{
				str[j++] = 32;
				x++;
			}
			x = 0;
			i++;
		}
		else
			str[j++] = s1[i++];
	}
	str[j] = '\0';
	return (str);
}
