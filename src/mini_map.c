/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:54:12 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/04 17:33:43 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

void	ft_print_square(t_game *game, int w, int h, char c)
{
	int color;
	if (c == '1')
		color = 13158600;
	else
		color= 6579300;
	int i = 0; int j = 0;
	while(i < 58) {
		j = 0;
		while(j < 58) {
			img_pix_put(game->img, (h*60) + i, (w*60) + j, color);
			++j;
		}
		++i;
	}
}

void	ft_show_mini(t_game *game)
{
	int i = 0; int j = 0;

	while (game->map.map[i]) {
		j = 0;
		while (game->map.map[i][j]) {
//			if (game->map.map[i][j] == "1")
			ft_print_square(game, i, j, game->map.map[i][j]);
			j++;
		}
		i++;
	}
}

void	ft_show_player(t_game *game)
{
	for (int i = -4; i < 5; ++i)
	{
		for (int j = -4; j < 5; ++j)
			img_pix_put(game->img, game->px + i, game->py + j, 2009780);
	}
	/*
	mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->px + 5, game->py , 2009780);
	mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->px + 5 , game->py + 1, 2009780);
	mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->px + 5 , game->py - 1, 2009780);
	mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->px + 6, game->py , 2009780);
	mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->px + 7, game->py , 2009780);
	*/
}

void	ft_draw_background(t_game *g)
{
	int i;
	int j;
	
	i = 0;
	while (i < W)
	{
		j = 0;
		while (j < H)	
		{
			if (j > H/2)
				img_pix_put(g->img, i, j, 2960670);
			else
				img_pix_put(g->img, i, j, 8882050);
			++j;
		}
		++i;
	}
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(int *)pixel = color;
}
