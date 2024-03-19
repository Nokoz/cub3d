/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:48:20 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/19 14:12:06 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/common.h"
bool	ft_collision(t_game *g, int key);
bool	ft_collision_side(t_game *g, int key);

void	ft_move_down(t_game *g)
{
	//check possible
	if (ft_collision(g, KEY_S))
	{
		g->py -= g->pdy;
		g->px -= g->pdx;
	}
}

void	ft_move_up(t_game *g)
{
	//check possible
	if (ft_collision(g, KEY_W))
	{
		g->px += g->pdx;
		g->py += g->pdy;
	}
}

void	ft_move_left(t_game *g)
{
	//check possible
//(sin pa ; -cos pa)	
	if (ft_collision_side(g, KEY_A))
	{
		g->px += sin(g->pa) * 5;
		g->py += -cos(g->pa) * 5;
	}
}

void	ft_move_right(t_game *g)
{
	//check possible
	if (ft_collision_side(g, KEY_D))
	{
		g->px += -sin(g->pa) * 5;
		g->py += cos(g->pa) * 5;
	}
}

bool	ft_collision(t_game *g, int key)
{
	float	dist;
	float	x;
	float	y;
	float	a;

	a = g->pa;
	if (key == KEY_S)
		a += 180.0;
	dist = 10.0;
	x = g->px + dist * cos(a);
	y = g->py + dist * sin(a);
	if (g->map.map[(int)y >> 6 ][(int)x >> 6] == '1')
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
	dist = 10.0;
	x = g->px + dist * cos(a);
	y = g->py + dist * sin(a);
	if (g->map.map[(int)y >> 6 ][(int)x >> 6] == '1')
		return (false);
	return (true);
}


void	ft_rotate(t_game *g, int key)
{
	if (key == KEY_RIGHT)
	{
		g->pa += 0.1;
		if (g->pa > 2 * M_PI)
			g->pa -= 2 * M_PI;
		g->pdx = cos(g->pa) * 5;
		g->pdy = sin(g->pa) * 5;
	}
	else if (key == KEY_LEFT)
	{
		g->pa -= 0.1;
		if (g->pa < 0)
			g->pa += 2 * M_PI;
		g->pdx = cos(g->pa) * 5;
		g->pdy = sin(g->pa) * 5;
	}
}

int	ft_key_handle(int key, t_game *game)
{
	if (key == KEY_W)
		ft_move_up(game);
	else if (key == KEY_D)
		ft_move_right(game);
	else if (key == KEY_S)
		ft_move_down(game);
	else if (key == KEY_A)
		ft_move_left(game);
	else if (key == KEY_RIGHT)
		ft_rotate(game, KEY_RIGHT);
	else if (key == KEY_LEFT)
		ft_rotate(game, KEY_LEFT);
	else if (key == KEY_ESC)
		exit(2);
	ft_frame_loop(game);
	return (0);
}
