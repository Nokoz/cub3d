/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noko.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:32:28 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/22 10:53:19 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/cub3d.h"

int	noko(t_datas *d)
{
	t_img	*img;
	t_ray	*ray;

	img = malloc(sizeof(t_img));
	if (!img)
	{
		free_all(d);
		error_exit(E_MALLOC);
	}
	ray = malloc(sizeof(t_ray));
	if (!ray)
	{
		free_all(d);
		error_exit(E_MALLOC);
	}
	d->game->img = img;
	d->game->ray = ray;
	ft_init_game_var(d);
	ft_init_win(d);
	mlx_hook(d->game->win_ptr, 02, 1L << 0, ft_key_handle, d);
	mlx_loop(d->game->mlx_ptr);
	return (0);
}

void	ft_init_game_var(t_datas *d)
{
	d->game->data = d;
	d->game->map.map = d->map;
	d->game->map.x = d->map_x;
	d->game->map.y = d->map_y;
	d->game->px = d->start_x * 64;
	d->game->py = d->start_y * 64;
	d->game->pa = ft_start_dri(d->orientation);
	d->game->pdx = cos(d->game->pa) * 5;
	d->game->pdy = sin(d->game->pa) * 5;
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

int	ft_frame_loop(t_game *g, t_datas *d)
{
	int	i;

	i = 0;
	g->img->img = new_img(g->mlx_ptr);
	g->img->addr = get_addr(g->img);
	ft_draw_background(d);
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
		ft_draw_walls(d, i);
		g->ray->ra += DR;
		i++;
	}
	put_img(g);
	destroy_img(g);
	return (0);
}
