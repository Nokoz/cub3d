/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:54:12 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/20 21:24:33 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/common.h"

void	ft_print_square(t_game *game, int w, int h, char c)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	if (c == '1')
		color = 13158600;
	else
		color = 6579300;
	while (i < 60)
	{
		j = 0;
		while (j < 60)
		{
			img_pix_put(game->img, (h * 64) + i, (w * 64) + j, color);
			++j;
		}
		++i;
	}
}

void	ft_show_mini(t_game *game)
{
	int	i;
	int	j;

	i = 0;
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
void ft_show_player(t_game *game)
{
    int i;
    int j;

	i = -4;
    while (i < 5)
    {
        j = -4;
        while (j < 5)
        {
            img_pix_put(game->img, game->px + i, game->py + j, 2009780);
            j++;
        }
        i++;
    }
}

void ft_draw_line(t_game *g, int x, int offset, float wall_h)
{
	int y1;
	int ly;
	int	i;
	int	color;
	int	texY;
	int	texX;
	double step;
	double texpos;

	y1 = offset + wall_h;
	ly = offset;
	i = 0; 
	color =  /*0; */16724530;

	step = 128 / wall_h;
	texpos = (ly - 540 + wall_h/2) * step;

	texX = (int) (g->ray->ry / 2.0) % 128;
//	texX = ft_set_texture_x(g);
	printf("TX = %d\n", texX);
	while (ly + i < y1)
	{
		texY = (int)texpos & (128-1);
		texpos += step;
		color = draw_texture(g->data, (int)texX, texY);
		img_pix_put(g->img, x, ly + i, color);
		i++;
	}
}

int	ft_set_texture_x(t_game *g)
{
	int	tx;
	if (g->ray->side == 0)
	{
		tx = (g->ray->ry - floor(g->ray->ry)) * 128;
//		if (g->ray->ra > (float)M_PI && g->ray->ra != (float) M_PI * 2) // looking up
		if (g->ray->ra < (float)M_PI && g->ray->ra > 0) // looking down
			tx = (128 - tx - 1);
	}
	else
	{
		tx = (g->ray->rx - floor(g->ray->rx)) * 128;
		if (g->ray->ra < (float)M_PI_2 || g->ray->ra > (3 * (float)M_PI_2))// looking right
			tx = (128 - tx - 1);
	}
	return (tx);
}

void ft_show_ray(t_game *g)
{
	//fin de rayon
	int x1 = g->ray->rx; int y1 = g->ray->ry;	
	int lx = g->px; int ly = g->py;

	int dx = abs(x1 - lx);
	int dy = abs(y1 - ly);
	int sx, sy, err, e2;

	if (lx < x1)
		sx = 1;
	else
		sx = -1;
	if (ly < y1)
		sy = 1;
	else
		sy = -1;
	err = dx - dy;
	while (1)
	{
		img_pix_put(g->img, (int)lx, (int)ly, 3668530);
		if (lx == x1 && ly == y1)
			break ;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			lx += sx;
		}
		if (lx == x1 && ly == y1)
		{
			img_pix_put(g->img, (int)lx, (int)ly, 3668530);
			break ;
		}
		if (e2 < dx)
		{
			err += dx;
			ly += sy;
		}
	}
}

void	ft_draw_background(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < W)
	{
		j = 0;
		while (j < H)	
		{
			if (j > H / 2)
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
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}
