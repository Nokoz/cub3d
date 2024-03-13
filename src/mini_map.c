/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:54:12 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/13 16:53:39 by gvardaki         ###   ########.fr       */
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
	while(i < 62) {
		j = 0;
		while(j < 62) {
			img_pix_put(game->img, (h*64) + i, (w*64) + j, color);
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
//			if (game->map.map[i][j] == '1')
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

void ft_show_ray(t_game *g)
{
	//fin de rayon
	int x1 = g->ray->rx; int y1 = g->ray->ry;	
	int lx = g->px; int ly = g->py;
	
	int dx = abs(x1 - lx);
    int dy = abs(y1 - ly);
    int sx, sy, err, e2;

    if (lx < x1) {
        sx = 1;
    } else {
        sx = -1;
    }

    if (ly < y1) {
        sy = 1;
    } else {
        sy = -1;
    }

    err = dx - dy;

    while (1) {
		img_pix_put(g->img, (int)lx, (int)ly, 3668530);

        if (lx == x1 && ly == y1) {
            break;
        }

        e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            lx += sx;
        }

        if (lx == x1 && ly == y1) {
			img_pix_put(g->img, (int)lx, (int)ly, 3668530);
            break;
        }

        if (e2 < dx) {
            err += dx;
            ly += sy;
        }
    }
}

void ft_show_dir(t_game *g)
{
	//fin du viseur
	int x1 = g->px + 15 * cos(g->pa); int y1 = g->py + 15 * sin(g->pa);	
	int lx = g->px; int ly = g->py;
	
	int dx = abs(x1 - lx);
    int dy = abs(y1 - ly);
    int sx, sy, err, e2;

    if (lx < x1) {
        sx = 1;
    } else {
        sx = -1;
    }

    if (ly < y1) {
        sy = 1;
    } else {
        sy = -1;
    }

    err = dx - dy;

    while (1) {
		img_pix_put(g->img, (int)lx, (int)ly, 16724530);

        if (lx == x1 && ly == y1) {
            break;
        }

        e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            lx += sx;
        }

        if (lx == x1 && ly == y1) {
			img_pix_put(g->img, (int)lx, (int)ly, 16724530);
            break;
        }

        if (e2 < dx) {
            err += dx;
            ly += sy;
        }
    }
	/*
	img_pix_put(g->img, (int)lx, (int)ly,8882050);
	img_pix_put(g->img, (int)lx+1, (int)ly, 8882050);
	img_pix_put(g->img, (int)lx+2, (int)ly, 8882050);
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
