/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:54:12 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/21 10:30:03 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/common.h"

void ft_draw_line(t_game *g, int x, int offset, float wall_h)
{
	int y1;
	int ly;
	int	i;
	int	texY;
	int	texX;
	int color;
	double step;
	double texpos;

	y1 = offset + wall_h;
	ly = offset;
	i = 0; 

	step = 128 / wall_h;
	texpos = (ly - 540 + wall_h/2) * step;

	texX = ft_set_texture_x(g);
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
		tx = (int) (g->ray->rx * 2.0) % 128;
	else
		tx = (int) (g->ray->ry * 2.0) % 128;
	/*
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
	*/
	return (tx);
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
