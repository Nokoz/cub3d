/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:32:28 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/19 15:41:54 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/common.h"

int	noko(t_datas *d)
{
//	t_game	*game;
//	t_map	map;
	t_img	*img;
	t_ray	*ray;

//	game = malloc(sizeof(t_game));
	img = malloc(sizeof(t_img));
	ray = malloc(sizeof(t_ray));
//	char *mapy = "1111111\n1100001\n1000101\n1000001\n1100001\n1111111\n";
//	char *mapy = "11111111111111111111111111111\n11110111111111011101010010001\n11000000110101011100000010001\n10000000000000001100000010001\n10000000000000000001010000001\n11000001110101011111011110N0111\n11110111 1110101 101111010001\n11111111 1111111 111111111111\n";

//	map.map = ft_split(mapy, '\n');
	d->game->data = d;
	d->game->map.map = d->map;
	d->game->img = img;
	d->game->ray = ray;
	d->game->px = d->start_x *64;
	d->game->py = d->start_y *64;
	d->game->pa = ft_start_dri(d->orientation);// check orientation
	d->game->pdx = cos(d->game->pa) * 5;
	d->game->pdy = sin(d->game->pa) * 5;
	ft_init_win(d);

	mlx_hook(d->game->win_ptr, 02, 1L<<0, ft_key_handle, d->game);
//	mlx_loop_hook(game->mlx_ptr, ft_frame_loop, game);
	mlx_loop(d->game->mlx_ptr);

	return (0);
}

float ft_start_dri(char c)
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

int		ft_frame_loop(t_game *g)
{
	g->img->img = new_img(g->mlx_ptr);
	g->img->addr = get_addr(g->img);
	int i = 0;

		ft_draw_background(g);
		g->ray->ra = g->pa - (DR * 40);
		if (g->ray->ra < 0)
			g->ray->ra += 2 * M_PI;
		if (g->ray->ra > 2 * M_PI)
			g->ray->ra -= 2 * M_PI;
		while (i < 80)
		{
			if (g->ray->ra < 0)
				g->ray->ra += 2 * M_PI;
			if (g->ray->ra > 2 * M_PI)
				g->ray->ra -= 2 * M_PI;
	//		ft_ray_dist(g);
			ft_draw_walls(g, i);
		//	ft_show_ray(g);
			g->ray->ra += DR;
			i++;
		}
//		ft_show_mini(g);
		ft_show_player(g);
		put_img(g);
		destroy_img(g);
		return (0);
}

void	ft_draw_walls(t_game *g, int ray)
{
	float	dist;
	float	wall_h;
	float	line_o;
	float	ca;

	ca = g->pa - g->ray->ra; //fisheye
	dist = ft_ray_dist(g);
	if (ca < 0)
		ca += 2 * M_PI;
	if (ca > 2 * M_PI)
		ca -= 2 * M_PI;
	dist *= cos(ca);
	wall_h = ft_get_wall_h(g, dist);
	line_o = 540 - wall_h / 2;
	ft_draw_ray(g, wall_h, line_o, ray);
}

void	ft_draw_ray(t_game *g, float wall_h, float line_o, int ray)
{
	int	i;

	i = 0;
	while (i < 24)
	{
		ft_draw_line(g, (ray * 24 + i), line_o, wall_h);
		i++;
	}
}

float	ft_get_wall_h(t_game *g, float dist)
{
	float	ret;
	(void)g;

	ret = ((30) * 1080) / dist;
	if (ret > 1080)
		return (1080);
	return (ret);
}
