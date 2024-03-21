/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:48:49 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/21 14:21:46 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/cub3d.h"

float	ft_ray_dist(t_datas *d)
{
	float	len_h;
	float	len_v;
	int		end[2];

	len_h = ft_cast_hori(d->game->ray, d, d->game->px, d->game->py);
	end[0] = d->game->ray->rx;
	end[1] = d->game->ray->ry;
	d->game->ray->side = 1;
	len_v = ft_cast_verti(d->game->ray, d, d->game->px, d->game->py);
	if (len_h < len_v)
	{
		d->game->ray->side = 0;
		d->game->ray->rx = end[0];
		d->game->ray->ry = end[1];
		return (len_h);
	}
	return (len_v);
}

void	ft_iter_offset(t_ray *ray, t_datas *datas, float xo, float yo)
{
	int	x;
	int	y;

	ray->dof = 0;
	while (ray->dof < 20)
	{
		x = (int)(ray->rx) >> 6;
		y = (int)(ray->ry) >> 6;
		if (x < 0 || y < 0 || x >= datas->game->map.x
			|| y >= datas->game->map.y || datas->game->map.map[y][x] == '1')
			ray->dof = 20;
		else
		{
			ray->rx += xo;
			ray->ry += yo;
			ray->dof += 1;
		}
	}
}

float	ft_cast_hori(t_ray *ray, t_datas *datas, float x, float y)
{
	float	a_tan;

	a_tan = -1 / tan(ray->ra);
	if (ray->ra > (float)M_PI && ray->ra != (float) M_PI * 2)
	{
		ray->ry = (((int)y >> 6) << 6) - 0.0001f;
		ray->rx = (y - ray->ry) * a_tan + x;
		ray->yo = -64;
	}
	else if (ray->ra < (float)M_PI && ray->ra > 0)
	{
		ray->ry = (((int)y >> 6) << 6) + 64;
		ray->rx = (y - ray->ry) * a_tan + x;
		ray->yo = 64;
	}
	if (ray->ra == 0 || ray->ra == (float)M_PI)
	{
		ray->rx = x;
		ray->ry = y;
		return (MAXFLOAT);
	}
	ray->xo = -ray->yo * a_tan;
	ft_iter_offset(ray, datas, ray->xo, ray->yo);
	return (sqrtf(powf((ray->rx - x), 2) + powf((ray->ry - y), 2)));
}

float	ft_cast_verti(t_ray *ray, t_datas *datas, float x, float y)
{
	float	n_tan;

	n_tan = -tan(ray->ra);
	if (ray->ra > (float)M_PI_2 && ray->ra < (3 * (float) M_PI_2))
	{
		ray->rx = (((int)x >> 6) << 6) - 0.0001f;
		ray->xo = -64;
	}
	else if (ray->ra < (float)M_PI_2 || ray->ra > (3 * (float)M_PI_2))
	{
		ray->rx = (((int)x >> 6) << 6) + 64;
		ray->xo = 64;
	}
	ray->ry = (x - ray->rx) * n_tan + y;
	if (ray->ra == (float)M_PI_2 || ray->ra == (3 * (float)M_PI_2))
	{
		ray->rx = x;
		ray->ry = y;
		return (MAXFLOAT);
	}
	ray->yo = -ray->xo * n_tan;
	ft_iter_offset(ray, datas, ray->xo, ray->yo);
	return (sqrtf(powf((ray->rx - x), 2) + powf((ray->ry - y), 2)));
}
