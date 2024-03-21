/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:18:27 by salowie           #+#    #+#             */
/*   Updated: 2024/03/21 15:17:34 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/cub3d.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	flen;
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	flen = ft_strlen(s);
	if (start > flen)
		start = flen;
	if (len > flen - start)
		len = flen - start;
	else if (flen < start)
		len = 0;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	i = 0;
	while (i <= size)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

int	nbr_tab(char *str)
{
	int	i;
	int	nbr_tab;

	i = 0;
	nbr_tab = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			nbr_tab++;
		i++;
	}
	return (nbr_tab);
}

int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;
	char		*s;

	s = (char *)str;
	res = 0;
	sign = 1;
	while ((*s > 8 && *s < 14) || *s == 32)
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + *s - 48;
		s++;
	}
	return (res * sign);
}
