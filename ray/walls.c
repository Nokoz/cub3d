/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:19:31 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/21 11:49:03 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/common.h"

void	ft_draw_walls(t_game *g, int ray)
{
	float	dist;
	float	wall_h;
	float	line_o;
	float	ca;

	ca = g->pa - g->ray->ra;
	dist = ft_ray_dist(g);
	ft_set_wall_text(g->ray);
	if (ca < 0)
		ca += 2 * M_PI;
	if (ca > 2 * M_PI)
		ca -= 2 * M_PI;
	dist *= cos(ca);
	wall_h = ft_get_wall_h(g, dist);
	line_o = 540 - wall_h / 2;
	ft_draw_ray(g, wall_h, line_o, ray);
/*                                                                            */
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

void	ft_draw_ray(t_game *g, float wall_h, float line_o, int ray)
{
	int	i;

	i = 0;
	while (i < STRP_W)
	{
		ft_draw_line(g, (ray * STRP_W + i), line_o, wall_h);
		i++;
	}
}

float	ft_get_wall_h(t_game *g, float dist)
{
	float	ret;

	ret = ((40) * 1080) / dist;
	g->step = 128 / ret; //texture size
	g->ty_off = 0;
	if (ret > 1080)
	{
		g->ty_off = (ret - 1080) / 2.0;
		return (1080);
	}
	return (ret);
}
