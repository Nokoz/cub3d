/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:48:20 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/21 10:48:07 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/common.h"

void	ft_move_down(t_game *g)
{
	if (ft_collision(g, KEY_S))
	{
		g->py -= g->pdy;
		g->px -= g->pdx;
	}
}

void	ft_move_up(t_game *g)
{
	if (ft_collision(g, KEY_W))
	{
		g->px += g->pdx;
		g->py += g->pdy;
	}
}

void	ft_move_left(t_game *g)
{
	if (ft_collision_side(g, KEY_A))
	{
		g->px += sin(g->pa) * 5;
		g->py += -cos(g->pa) * 5;
	}
}

void	ft_move_right(t_game *g)
{
	if (ft_collision_side(g, KEY_D))
	{
		g->px += -sin(g->pa) * 5;
		g->py += cos(g->pa) * 5;
	}
}

int	ft_key_handle(int key, t_datas *d)
{
	if (key == KEY_W)
		ft_move_up(d->game);
	else if (key == KEY_D)
		ft_move_right(d->game);
	else if (key == KEY_S)
		ft_move_down(d->game);
	else if (key == KEY_A)
		ft_move_left(d->game);
	else if (key == KEY_RIGHT)
		ft_rotate(d->game, KEY_RIGHT);
	else if (key == KEY_LEFT)
		ft_rotate(d->game, KEY_LEFT);
	else if (key == KEY_ESC)
		exit(2);
	ft_frame_loop(d->game, d);
	return (0);
}
