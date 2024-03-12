/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:48:20 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/12 14:44:40 by gvardaki         ###   ########.fr       */
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

void	ft_rotate_right(t_game *g)
{
	g->pa += 0.1;
	if (g->pa > 2 * M_PI)
		g->pa -= 2 * M_PI;
	g->pdx = cos(g->pa) * 5;
	g->pdy = sin(g->pa) * 5;
}

void	ft_rotate_left(t_game *g)
{
	g->pa -= 0.1;
	if (g->pa < 0)
		g->pa += 2 * M_PI;
	g->pdx = cos(g->pa) * 5;
	g->pdy = sin(g->pa) * 5;
}
int		ft_key_handle(int key, t_game *game)
{
	if (key == KEY_W)
		ft_move_up(game);
	//	game->py -=5;
	if (key == KEY_D)
		ft_move_right(game);
//		game->px +=5;
	if (key == KEY_S)
		ft_move_down(game);
//		game->py +=5;
	if (key == KEY_A)
		ft_move_left(game);
//		game->px -=5;
	if (key == KEY_ESC)
		exit(2);
	if (key == KEY_RIGHT)
		ft_rotate_right(game);
	if (key == KEY_LEFT)
		ft_rotate_left(game);
	ft_frame_loop(game);
	return (0);
}
