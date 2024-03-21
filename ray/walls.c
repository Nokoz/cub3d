/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:48:26 by salowie           #+#    #+#             */
/*   Updated: 2024/03/21 14:23:26 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/cub3d.h"

void	ft_draw_walls(t_datas *datas, int ray)
{
	float	dist;
	float	wall_h;
	float	line_o;
	float	ca;

	ca = datas->game->pa - datas->game->ray->ra;
	dist = ft_ray_dist(datas);
	ft_set_wall_text(datas->game->ray);
	if (ca < 0)
		ca += 2 * M_PI;
	if (ca > 2 * M_PI)
		ca -= 2 * M_PI;
	dist *= cos(ca);
	wall_h = ft_get_wall_h(datas, dist);
	line_o = 540 - wall_h / 2;
	ft_draw_ray(datas, wall_h, line_o, ray);
}

void	ft_set_wall_text(t_ray *r)
{
	if (r->side == 0)
	{
		if (r->ra > (float)M_PI && r->ra != (float) M_PI * 2)
			r->wall = 'n';
		else
			r->wall = 's';
	}
	else
	{
		if (r->ra > (float)M_PI_2 && r->ra < (3 * (float) M_PI_2))
			r->wall = 'w';
		else
			r->wall = 'e';
	}
}

void	ft_draw_ray(t_datas *datas, float wall_h, float line_o, int ray)
{
	int	i;

	i = 0;
	while (i < STRP_W)
	{
		ft_draw_line(datas, (ray * STRP_W + i), line_o, wall_h);
		i++;
	}
}

float	ft_get_wall_h(t_datas *datas, float dist)
{
	float	ret;

	ret = ((40) * 1080) / dist;
	datas->game->step = 128 / ret; //texture size
	datas->game->ty_off = 0;
	if (ret > 1080)
	{
		datas->game->ty_off = (ret - 1080) / 2.0;
		return (1080);
	}
	return (ret);
}
