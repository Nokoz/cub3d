/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:17:56 by salowie           #+#    #+#             */
/*   Updated: 2024/03/19 14:49:59 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/common.h"

static char	*collect_strings(int fd)
{
	char	*strings_collected;
	char	*str;
	char	*temp;

	str = get_next_line(fd);
	strings_collected = NULL;
	while (str)
	{
		temp = strings_collected;
		strings_collected = ft_strjoin_mod(temp, str);
		free(temp);
		free(str);
		str = get_next_line(fd);
	}
	return (strings_collected);
}

char	**convert_doc(char *lib, t_datas *datas)
{
	int		fd;
	char	**doc;
	char	*strings_collected;

	doc = NULL;
	fd = open(lib, O_RDONLY);
	if (fd < 0)
	{
		free(datas);
		error_exit(E_FD);
	}
	strings_collected = collect_strings(fd);
	doc = ft_split(strings_collected, '\n');
	free(strings_collected);
	close(fd);
	return (doc);
}
