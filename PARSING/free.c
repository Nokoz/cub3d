/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:22:00 by salowie           #+#    #+#             */
/*   Updated: 2024/03/25 10:40:46 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/cub3d.h"

void	ft_freee(void **value)
{
	if (*value)
	{
		free(*value);
		*value = NULL;
	}
}

void	ft_free_2d_char(char ***str_ptr)
{
	char	**str;
	int		i;

	i = 0;
	str = *str_ptr;
	if (!str)
		return ;
	while (str && str[i])
	{
		ft_freee((void **)&str[i]);
		i++;
	}
	free(*str_ptr);
	*str_ptr = NULL;
}

static void	free_textures_individual(t_datas *datas, t_texture_struct *texture)
{
	if (!texture)
		return ;
	if (texture->xpm)
		mlx_destroy_image(datas->mlx, texture->xpm);
	if (texture != NULL)
		ft_freee((void **)&texture);
}

void	free_textures(t_datas *d)
{
	if (d == NULL || d->textures == NULL)
		return ;
	if (d->textures->ea != NULL)
		free_textures_individual(d, d->textures->ea);
	if (d->textures->we != NULL)
		free_textures_individual(d, d->textures->we);
	if (d->textures->so != NULL)
		free_textures_individual(d, d->textures->so);
	if (d->textures->no != NULL)
		free_textures_individual(d, d->textures->no);
	if (d->textures != NULL)
		ft_freee((void **)&d->textures);
	else
		return ;
}

void	free_all(t_datas *d)
{
	if (!d)
		return ;
	if (d->textures != NULL)
		free_textures(d);
	if (d->rgb_datas != NULL)
	{
		if (d->rgb_datas->str_floor != NULL)
			ft_freee((void **)&d->rgb_datas->str_floor);
		if (d->rgb_datas->str_sky != NULL)
			ft_freee((void **)&d->rgb_datas->str_sky);
		if (d->rgb_datas != NULL)
			ft_freee((void **)&d->rgb_datas);
	}
	if (d->map != NULL)
		ft_free_2d_char(&d->map);
	ft_free_ray(d);
	if (d->mlx)
	{
		mlx_clear_window(d->mlx, d->win);
		mlx_destroy_window(d->mlx, d->win);
	}
	if (d->mlx != NULL)
		free(d->mlx);
	if (d != NULL)
		ft_freee((void **)&d);
}
