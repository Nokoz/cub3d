/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:14:29 by gvardaki          #+#    #+#             */
/*   Updated: 2023/08/02 23:10:28 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_g_substr(char *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	if (!s)
		return (NULL);
	new_str = ft_g_strnew(len);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
		*(new_str + i++) = *(s + start++);
	return (new_str);
}

char	*ft_g_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	len_s1;

	len_s1 = ft_g_strlen(s1);
	str = ft_g_strnew(len_s1 + ft_g_strlen(s2));
	if (str != NULL)
	{
		i = 0;
		while (i < len_s1)
		{
			str[i] = s1[i];
			i++;
		}
		i = 0;
		while (i < ft_g_strlen(s2))
		{
			str[i + len_s1] = s2[i];
			i++;
		}
		str[i + len_s1] = '\0';
	}
	return (str);
}

char	*ft_g_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_g_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_g_strchr(const char *string, int chr)
{
	char	*str;

	str = (char *)string;
	while (*str != chr && *str != 0)
		str++;
	if (*str == chr)
		return (str);
	else
		return (NULL);
}
