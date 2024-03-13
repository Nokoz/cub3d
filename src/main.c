/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:32:28 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/13 17:28:22 by gvardaki         ###   ########.fr       */
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
	int i = -30;
	g->img->img = new_img(g->mlx_ptr);
	g->img->addr = get_addr(g->img);

		ft_draw_background(g);
		ft_show_mini(g);
		ft_show_player(g);
		ft_show_dir(g);
		g->ray->ra = g->pa-DR * 30;
		if (g->ray->ra < 0)
			g->ray->ra += 2 * M_PI;
		if (g->ray->ra > 2 * M_PI)
			g->ray->ra -= 2 * M_PI;
		while (i < 30)
		{
			if (g->ray->ra < 0)
				g->ray->ra += 2 * M_PI;
			if (g->ray->ra > 2 * M_PI)
				g->ray->ra -= 2 * M_PI;
			ft_ray_dist(g);
			ft_show_ray(g);
			g->ray->ra += DR;
			i++;
		}
		put_img(g);
		destroy_img(g);
		return (0);
}

float	ft_ray_dist(t_game *g)
{
	float	len_h, len_v;
	int		end[2];
	
		len_h = ft_cast_hori(g->ray, g, g->px, g->py);
		end[0] = g->ray->rx;
		end[1] = g->ray->ry;
		len_v = ft_cast_verti(g->ray, g, g->px, g->py);
		if (len_h < len_v)
		{
			//update endpoint
			g->ray->rx = end[0];
			g->ray->ry = end[1];
			return (len_h);
		}
		return (len_v);
}

void	ft_iter_offset(t_ray *ray, t_game *g, float xo, float yo)
{
	int x;
	int y;

	ray->dof = 0;
	while (ray->dof < 8)
	{
		x = (int) (ray->rx) >> 6;
		y = (int) (ray->ry) >> 6;
		if (x < 0 || y < 0 || x >= 5 || y >= 6 || g->map.map[y][x] == '1')
			ray->dof = 8;
		else
		{
			ray->rx += xo;
			ray->ry += yo;
			ray->dof += 1;
		}
	}
}

float	ft_cast_hori(t_ray *ray, t_game *g, float x, float y)
{
	float a_tan;

//	ray->ra = g->pa; //to move out, each ray own angle
	a_tan = -1 / tan(ray->ra);
	if (ray->ra > (float)M_PI && ray->ra != (float) M_PI * 2) // looking up
	{
		ray->ry = (((int)y >> 6) << 6) - 0.0001f;
		ray->rx = (y - ray->ry) * a_tan + x;
		ray->yo = -64;
	}
	else if (ray->ra < (float)M_PI && ray->ra > 0 )// looking down
	{
		ray->ry = (((int)y >> 6) << 6) + 64;
		ray->rx = (y - ray->ry) * a_tan + x;
		ray->yo = 64;
	}
	if (ray->ra == 0 || ray->ra == (float)M_PI) // looking horizon
	{
		ray->rx = x;
		ray->ry = y;
		return(MAXFLOAT);
	}
	ray->xo = -ray->yo * a_tan;
	ft_iter_offset(ray, g, ray->xo, ray->yo);
	return (sqrtf(powf((ray->rx -x), 2) + powf((ray->ry - y), 2))); //ray len
}

float	ft_cast_verti(t_ray *ray, t_game *g, float x, float y)
{
	float n_tan;

//	ray->ra = g->pa; //to move out, each ray own angle
	n_tan = -tan(ray->ra);
	if (ray->ra > (float)M_PI_2 && ray->ra < (3 * (float) M_PI_2)) // looking left
	{
		ray->rx = (((int)x >> 6) << 6) - 0.0001f;
		ray->xo = -64;
	}
	else if (ray->ra < (float)M_PI_2 || ray->ra > (3 *(float)M_PI_2))// looking right
	{
		ray->rx = (((int)x >> 6) << 6) + 64;
		ray->xo = 64;
	}
	ray->ry = (x - ray->rx) * n_tan + y;
	if (ray->ra == (float)M_PI_2 || ray->ra == (3 * (float)M_PI_2)) // looking verticaly
	{
		ray->rx = x;
		ray->ry = y;
		return(MAXFLOAT);
	}
	ray->yo = -ray->xo * n_tan;
	ft_iter_offset(ray, g, ray->xo, ray->yo);
	return (sqrtf(powf((ray->rx -x), 2) + powf((ray->ry - y), 2))); //ray len
}
