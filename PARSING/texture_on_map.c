/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_on_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:17:03 by salowie           #+#    #+#             */
/*   Updated: 2024/03/21 10:42:23 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/common.h"

int	draw_texture(t_datas *datas, int x, int y)
{
	int	color;

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

// Fonction pour obtenir la couleur d'un pixel à une position spécifique
int get_pixel_color(t_texture_struct *texture, int x, int y)
{
    // Obtenez les informations sur les pixels de l'image
    texture->data = mlx_get_data_addr(texture->xpm, &texture->bpp, &texture->size_l, &texture->endian);

    // Calculez l'index du pixel dans le tableau de données
    int index = (y * texture->size_l) + (x * (texture->bpp / 8));

    // Accédez à la valeur du pixel à l'index calculé
    unsigned int color = *(unsigned int *)(texture->data + index);

    // La valeur de couleur est généralement dans l'ordre BGR (little endian)
    // Vous pouvez la convertir en RGB ou utiliser les composantes individuelles en fonction de vos besoins
    int red = (color & 0xFF0000) >> 16;
    int green = (color & 0x00FF00) >> 8;
    int blue = color & 0x0000FF;

    return (rgbtoint(red, green, blue));
}

// mlx_get_color_value();
