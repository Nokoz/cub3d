/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:48:20 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/14 09:55:43 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

void	ft_move_down(t_game *g)
{
	//check possible
	
	g->py-=g->pdy;
	g->px-=g->pdx;
}

void	ft_move_up(t_game *g)
{
	//check possible
	
	g->px+=g->pdx;
	g->py+=g->pdy;
}

void	ft_move_left(t_game *g)
{
	//check possible
//(sin pa ; -cos pa)	
	g->px += sin(g->pa) * 5;
	g->py += -cos(g->pa) * 5;
}

void	ft_move_right(t_game *g)
{
	//check possible
	
	g->px += -sin(g->pa) * 5;
	g->py += cos(g->pa) * 5;
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

int		ft_key_handle(int key, t_game *game)
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
