/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:34:14 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/22 10:48:28 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/cub3d.h"

void	ft_free_ray(t_datas *d)
{
	if (d->game->ray != NULL)
		ft_freee((void **)&d->game->ray);
	if (d->game->img != NULL)
		ft_freee((void **)&d->game->img);
	if (d->game != NULL)
		ft_freee((void **)&d->game);
}
