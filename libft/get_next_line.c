/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:15:30 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/11 17:56:15 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* free if !stack */
char	*get_next_line(int fd)
{
	static char	*stake;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stake = ft_g_read(fd, stake);
	if (!stake)
	{
		return (NULL);
	}
	line = ft_g_line(stake);
	stake = ft_g_next(stake);
	return (line);
}

/* free if read == -1 */
char	*ft_g_read(int fd, char *stake)
{
	char	*buffer;
	int		read_value;

	buffer = ft_g_strnew(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_value = 1;
	while (read_value > 0)
	{
		read_value = read(fd, buffer, BUFFER_SIZE);
		if (read_value == -1)
		{
			return (NULL);
		}
		buffer[read_value] = '\0';
		stake = ft_g_join(stake, buffer);
		if (ft_g_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stake);
}

char	*ft_g_join(char *stake, char *buff)
{
	char	*joined;

	joined = ft_g_strjoin(stake, buff);
	free(stake);
	return (joined);
}

char	*ft_g_line(char *stake)
{
	char	*new_line;
	int		i;

	i = 0;
	if (!stake[i])
		return (NULL);
	while (stake[i] && stake[i] != '\n')
		i++;
	new_line = ft_g_strnew(i + 1);
	i = 0;
	while (stake[i] && stake[i] != '\n')
	{
		new_line[i] = stake[i];
		i++;
	}
	if (stake[i] && stake[i] == '\n')
		new_line[i] = '\n';
	return (new_line);
}

char	*ft_g_next(char *stake)
{
	char	*new_stake;
	int		i;

	i = 0;
	while (stake[i] && stake[i] != '\n')
		i++;
	if (!stake[i])
	{
		free(stake);
		return (NULL);
	}
	new_stake = ft_g_substr(stake, i + 1, ft_g_strlen(stake) - i);
	if (!new_stake)
	{
		free(stake);
		return (NULL);
	}
	free(stake);
	return (new_stake);
}
