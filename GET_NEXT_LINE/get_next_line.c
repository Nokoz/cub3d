/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:47:22 by salowie           #+#    #+#             */
/*   Updated: 2024/02/29 16:31:09 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_keep_left(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		i++;
	temp = malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		temp[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_keep_right(char *str)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		i++;
	temp = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!temp)
		return (NULL);
	j = 0;
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = '\0';
	return (temp);
}

char	*ft_read(int fd, char *keep_str, char *temp)
{
	int		bytes_read;
	char	buffer[BUFFER_SIZE + 1];

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free(&keep_str));
		buffer[bytes_read] = '\0';
		temp = keep_str;
		keep_str = ft_strjoin_mod(temp, buffer);
		free(temp);
		if (!keep_str)
			return (NULL);
		if (ft_strchr(buffer, '\n') != 0)
			break ;
	}
	if (bytes_read == 0 && keep_str[0] == '\0')
		return (ft_free(&keep_str));
	return (keep_str);
}

char	*get_next_line(int fd)
{
	static char	*keep_str = NULL;
	char		*line;
	char		*temp;

	temp = NULL;
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	keep_str = ft_read(fd, keep_str, temp);
	if (!keep_str)
		return (NULL);
	line = ft_keep_left(keep_str);
	if (!line)
		return (ft_free(&keep_str));
	temp = keep_str;
	keep_str = ft_keep_right(temp);
	free(temp);
	if (!keep_str)
		return (ft_free(&line));
	return (line);
}
