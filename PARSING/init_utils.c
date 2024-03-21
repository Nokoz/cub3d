/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:32:57 by salowie           #+#    #+#             */
/*   Updated: 2024/03/21 14:23:58 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/cub3d.h"

int	is_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == '1' || str[i] == '0' || str[i] == 'N' || str[i] == 'S'
				|| str[i] == 'W' || str[i] == 'E' || str[i] == 32 
				|| str[i] == '\t'))
			return (1);
		i++;
	}
	return (0);
}

char	**copy_map(char **doc, int i, t_datas *datas)
{
	int		j;
	int		map_lenght;
	char	**mappy;

	j = 0;
	map_lenght = ft_strlen_double_tab(doc) - i;
	mappy = malloc(sizeof(char *) * (map_lenght + 1));
	if (!mappy)
	{
		free_all(datas);
		error_exit(E_MALLOC);
	}
	while (doc[i])
	{
		mappy[j] = ft_strdup_no_tab(doc[i], 0, 0, 0);
		j++;
		i++;
	}
	mappy[j] = NULL;
	return (mappy);
}

int	exist(char *wall_side_str, t_datas *datas)
{
	if (wall_side_str != NULL)
	{
		free_all(datas);
		error_exit(E_DATAS);
	}
	return (0);
}
