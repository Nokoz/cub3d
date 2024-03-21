/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:54:12 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/21 15:57:14 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/cub3d.h"

void	ft_draw_line(t_datas *datas, int x, int offset, float wall_h)
{
	int		ly;
	int		tex_y;
	int		tex_x;
	int		color;
	double	texpos;

	ly = offset;
	texpos = datas->game->step * datas->game->ty_off;
	tex_x = ft_set_texture_x(datas);
	while (ly < (offset + wall_h))
	{
		tex_y = (int)texpos & (datas->textures->no->w - 1);
		color = draw_texture(datas, (int)tex_x, tex_y);
		img_pix_put(datas->game->img, x, ly, color);
		texpos += datas->game->step;
		ly++;
	}
}

int	ft_set_texture_x(t_datas *datas)
{
	int	tx;

	if (datas->game->ray->side == 0)
		tx = (int)(datas->game->ray->rx * 2.0) % datas->textures->no->w;
	else
		tx = (int)(datas->game->ray->ry * 2.0) % datas->textures->no->w;
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
