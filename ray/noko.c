/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:32:28 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/21 10:24:15 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/common.h"

int	noko(t_datas *d)
{
	t_img	*img;
	t_ray	*ray;

	img = malloc(sizeof(t_img));
	ray = malloc(sizeof(t_ray));
	d->game->data = d;
	d->game->map.map = d->map;
	d->game->map.x = d->map_x;
	d->game->map.y = d->map_y;
	d->game->img = img;
	d->game->ray = ray;
	d->game->px = d->start_x * 64;
	d->game->py = d->start_y * 64;
	d->game->pa = ft_start_dri(d->orientation);
	d->game->pdx = cos(d->game->pa) * 5;
	d->game->pdy = sin(d->game->pa) * 5;
	ft_init_win(d);
	mlx_hook(d->game->win_ptr, 02, 1L << 0, ft_key_handle, d->game);
//	mlx_loop_hook(d->game->mlx_ptr, ft_frame_loop, d->game);
	mlx_loop(d->game->mlx_ptr);
	return (0);
}

float	ft_start_dri(char c)
{
	if (c == 'S')
		return (M_PI / 2);
	else if (c == 'N')
		return ((3 * M_PI) / 2);
	else if (c == 'W')
		return (M_PI);
	else if (c == 'E')
		return (2 * M_PI);
	return (0);
}

void	ft_init_win(t_datas *d)
{
	d->game->mlx_ptr = d->mlx;
	d->game->win_ptr = d->win;
}

int	ft_frame_loop(t_game *g)
{
	int	i;

	i = 0;
	g->img->img = new_img(g->mlx_ptr);
	g->img->addr = get_addr(g->img);
	ft_draw_background(g);
	g->ray->ra = g->pa - (DR * 320);
	if (g->ray->ra < 0)
		g->ray->ra += 2 * M_PI;
	if (g->ray->ra > 2 * M_PI)
		g->ray->ra -= 2 * M_PI;
	while (i < 640)
	{
		if (g->ray->ra < 0)
			g->ray->ra += 2 * M_PI;
		if (g->ray->ra > 2 * M_PI)
			g->ray->ra -= 2 * M_PI;
		ft_draw_walls(g, i);
		g->ray->ra += DR;
		i++;
	}
	put_img(g);
	destroy_img(g);
	return (0);
}
