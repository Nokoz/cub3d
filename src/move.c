/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:48:20 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/05 12:01:15 by gvardaki         ###   ########.fr       */
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

void	ft_move_right(t_game *g)
{
	//check possible
	
	g->py+=g->pdy;
	g->px-=g->pdx;
}

void	ft_move_left(t_game *g)
{
	//check possible
	
	g->py-=g->pdy;
	g->px+=g->pdx;
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
