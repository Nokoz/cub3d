/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:54:12 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/21 11:52:01 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/common.h"

void	ft_draw_line(t_game *g, int x, int offset, float wall_h)
{
	int	y1;
	int	ly;
	int	i;
	int	texY;
	int	texX;
	int color;
//	double step;
	double texpos;

	y1 = offset + wall_h;
	ly = offset;
	i = 0; 

//	step = 128 / wall_h;
//	texpos = (ly - 540 + wall_h/2) * g->step;

	texX = ft_set_texture_x(g);
	texY = g->ty_off * g->step;
	while (ly + i < y1)
	{
		color = draw_texture(g->data, (int)texX, texY);
		img_pix_put(g->img, x, ly + i, color);
		texY += g->step;
		i++;
	}
}

int	ft_set_texture_x(t_game *g)
{
	int	tx;

	if (g->ray->side == 0)
		tx = (int)(g->ray->rx * 2.0) % 128;
	else
		tx = (int)(g->ray->ry * 2.0) % 128;
	return (tx);
}

void	ft_draw_background(t_datas *d)
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
				img_pix_put(d->game->img, i, j, d->rgb_datas->floor);
			else
				img_pix_put(d->game->img, i, j, d->rgb_datas->sky);
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
