/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:32:28 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/12 16:36:18 by gvardaki         ###   ########.fr       */
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
	game->pa = 0;
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

		ft_draw_background(g);
		ft_show_mini(g);
		ft_show_player(g);
		ft_show_dir(g);
		ft_cast_ray(g);
	ft_printf("ici\n");
		ft_show_ray(g);
		put_img(g);
		destroy_img(g);
		return (0);
}

void	ft_cast_ray(t_game *g)
{
	float aTan;
	g->ray->ra = g->pa;
	g->ray->r = 0;
	while (g->ray->r < 0)
	{
		g->ray->dof = 0;
		aTan = -1 / tan(g->ray->ra);
		if (g->ray->ra > M_PI) // looking up
		{
			g->ray->ry = (((int)g->py >> 6) << 6) - 0.0001;
			g->ray->rx = (g->py - g->ray->ry) * aTan + g->px;
			g->ray->yo = -64;
			g->ray->xo = -g->ray->yo * aTan;
		}
		if (g->ray->ra < M_PI) // looking down
		{
			g->ray->ry = (((int)g->py >> 6) << 6) + 64;
			g->ray->rx = (g->py - g->ray->ry) * aTan + g->px;
			g->ray->yo = 64;
			g->ray->xo = -g->ray->yo * aTan;
		}
		if (g->ray->ra == 0 || g->ray->ra == M_PI) // looking horizon
		{
			g->ray->rx = g->px;
			g->ray->ry = g->py;
			g->ray->dof = 8;
		}
		while (g->ray->dof < 8)
		{
			g->ray->mx = (int) (g->ray->rx) >> 6;
			g->ray->my = (int) (g->ray->ry) >> 6;
			if (g->map.map[g->ray->mx][g->ray->my] == 1) //hit wall
				g->ray->dof = 8;
			else //next line
			{
				g->ray->rx = g->ray->xo;
				g->ray->ry = g->ray->yo;
				g->ray->dof += 1;
			}

		}
		g->ray->r++;
	}
}
