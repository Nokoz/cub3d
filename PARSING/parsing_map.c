/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:35:28 by salowie           #+#    #+#             */
/*   Updated: 2024/03/21 14:24:19 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/cub3d.h"

static void	sizeof_map(t_datas *datas)
{
	int	i;
	int	currentlinewidth;

	datas->map_y = 0;
	datas->map_x = 0;
	i = 0;
	while (datas->map[i] != NULL)
	{
		currentlinewidth = 0;
		while (datas->map[i][currentlinewidth] != '\0')
			currentlinewidth++;
		if (currentlinewidth > datas->map_x)
			datas->map_x = currentlinewidth;
		i++;
		datas->map_y++;
	}
}

static int	nbr_of_player(t_datas *datas)
{
	int	x;
	int	y;

	y = 0;
	datas->nbr_of_player = 0;
	while (datas->map[y] && y <= ft_strlen_double_tab(datas->map))
	{
		x = 0;
		while (datas->map[y][x] && x <= ft_strlen(datas->map[y]))
		{
			if (datas->map[y][x] == 'N' || datas->map[y][x] == 'S' ||
				datas->map[y][x] == 'W' || datas->map[y][x] == 'E')
				datas->nbr_of_player += 1;
			x++;
		}
		y++;
	}
	if (datas->nbr_of_player != 1)
		return (1);
	return (0);
}

int	check_map(t_datas *datas)
{
	if (nbr_of_player(datas) == 1)
	{
		free_all(datas);
		error_exit(E_PLAYER);
	}
	dupmap_init(datas);
	sizeof_map(datas);
	return (0);
}
