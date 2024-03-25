/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_on_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:17:03 by salowie           #+#    #+#             */
/*   Updated: 2024/03/25 09:45:52 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/cub3d.h"

int	draw_texture(t_datas *datas, int x, int y)
{
	int	color;

	color = 0;
	if (datas->game->ray->wall == 'e')
		color = get_pixel_color(datas->textures->ea, x, y);
	else if (datas->game->ray->wall == 'w')
		color = get_pixel_color(datas->textures->we, x, y);
	else if (datas->game->ray->wall == 'n')
		color = get_pixel_color(datas->textures->no, x, y);
	else if (datas->game->ray->wall == 's')
		color = get_pixel_color(datas->textures->so, x, y);
	return (color);
}

int	get_pixel_color(t_texture_struct *texture, int x, int y)
{
	int				index;
	int				red;
	int				green;
	int				blue;
	unsigned int	color;

	texture->data = mlx_get_data_addr(texture->xpm, &texture->bpp,
			&texture->size_l, &texture->endian);
	index = (y * texture->size_l) + (x * (texture->bpp / 8));
	color = *(unsigned int *)(texture->data + index);
	red = (color & 0xFF0000) >> 16;
	green = (color & 0x00FF00) >> 8;
	blue = color & 0x0000FF;
	return (rgbtoint(red, green, blue));
}
