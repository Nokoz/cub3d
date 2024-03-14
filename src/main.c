/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:32:28 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/14 15:35:04 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

int	main(int ac, char **av)
{
	t_game	*game;
	t_map	map;
	t_img	*img;
	t_ray	*ray;
	(void)ac;
	(void)av;
	ft_printf("CUB3D\n");

	game = malloc(sizeof(t_game));
	img = malloc(sizeof(t_img));
	ray = malloc(sizeof(t_ray));
	char *mapy = "11111\n10001\n10101\n10001\n10001\n11111\n";

	map.map = ft_split(mapy, '\n');
	game->map = map;
	game->img = img;
	game->ray = ray;
	game->px = 150;
	game->py = 250;
	game->pa = M_PI/4;
	game->pdx = cos(game->pa) * 5;
	game->pdy = sin(game->pa) * 5;
	ft_init_win(game);

	mlx_hook(game->win_ptr, 02, 1L<<0, ft_key_handle, game);
//	mlx_loop_hook(game->mlx_ptr, ft_frame_loop, game);
	mlx_loop(game->mlx_ptr);

	return (0);
}

void	ft_init_win(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, W, H, "cub3d");
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
//			ft_ray_dist(g);
			ft_draw_walls(g, i);
//			ft_show_ray(g);
			g->ray->ra += DR;
			i++;
		}
		ft_show_mini(g);
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
