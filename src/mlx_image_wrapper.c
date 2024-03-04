/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_wrapper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:15:05 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/04 16:28:06 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

void	*new_img(void *mlx_ptr)
{
	return (mlx_new_image(mlx_ptr, W, H));
}

char	*get_addr(t_img *i)
{
	return (mlx_get_data_addr(i->img, &i->bpp, &i->line_len, &i->endian));
}

int	put_img(t_game *g)
{
	return (mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img->img, 0, 0));
}

int	destroy_img(t_game *g)
{
	return (mlx_destroy_image(g->mlx_ptr, g->img->img));
}
