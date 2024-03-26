/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:57:09 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/26 09:14:55 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/cub3d.h"

bool	ft_collision(t_game *g, int key)
{
	float	dist;
	float	x;
	float	y;
	float	a;

	a = g->pa;
	if (key == KEY_S)
		a += 180.0;
	dist = 5.0;
	x = g->px + dist * cos(a);
	y = g->py + dist * sin(a);
	if (g->map.map[(int)y >> 6][(int)x >> 6] != '0'
			&& g->map.map[(int)y >> 6][(int)x >> 6] != 'N'
				&& g->map.map[(int)y >> 6][(int)x >> 6] != 'W'
					&& g->map.map[(int)y >> 6][(int)x >> 6] != 'S'
						&& g->map.map[(int)y >> 6][(int)x >> 6] != 'E')
		return (false);
	return (true);
}

bool	ft_collision_side(t_game *g, int key)
{
	float	dist;
	float	x;
	float	y;
	float	a;

	a = g->pa - (M_PI / 2);
	if (key == KEY_D)
		a = g->pa + (M_PI / 2);
	dist = 5.0;
	x = g->px + dist * cos(a);
	y = g->py + dist * sin(a);
	if (g->map.map[(int)y >> 6][(int)x >> 6] != '0'
			&& g->map.map[(int)y >> 6][(int)x >> 6] != 'N'
				&& g->map.map[(int)y >> 6][(int)x >> 6] != 'W'
					&& g->map.map[(int)y >> 6][(int)x >> 6] != 'S'
						&& g->map.map[(int)y >> 6][(int)x >> 6] != 'E')
		return (false);
	return (true);
}

void	ft_rotate(t_game *g, int key)
{
	if (key == KEY_RIGHT)
	{
		g->pa += 0.07;
		if (g->pa > 2 * M_PI)
			g->pa -= 2 * M_PI;
		g->pdx = cos(g->pa) * 5;
		g->pdy = sin(g->pa) * 5;
	}
	else if (key == KEY_LEFT)
	{
		g->pa -= 0.07;
		if (g->pa < 0)
			g->pa += 2 * M_PI;
		g->pdx = cos(g->pa) * 5;
		g->pdy = sin(g->pa) * 5;
	}
}
