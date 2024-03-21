/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:48:50 by salowie           #+#    #+#             */
/*   Updated: 2024/03/21 14:24:04 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/cub3d.h"

static int	ft_strcmp_mod(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static int	check_format_cub(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len < 4)
		return (1);
	return (ft_strcmp_mod(str + len - 4, ".cub"));
}

void	check_arg(int argc, char *lib, t_datas *datas)
{
	if (argc != 2)
	{
		free(datas);
		error_exit(E_ARG);
	}
	if (check_format_cub(lib) != 0)
	{
		free(datas);
		error_exit(E_FILE);
	}
}

int	assign_textures(t_datas *d)
{
	d->textures->no->xpm = mlx_xpm_file_to_image(d->mlx,
			d->textures->no->str, &d->textures->no->w, &d->textures->no->h);
	d->textures->so->xpm = mlx_xpm_file_to_image(d->mlx, d->textures->so->str, 
			&d->textures->so->w, &d->textures->so->h);
	d->textures->we->xpm = mlx_xpm_file_to_image(d->mlx, d->textures->we->str, 
			&d->textures->we->w, &d->textures->we->h);
	d->textures->ea->xpm = mlx_xpm_file_to_image(d->mlx, d->textures->ea->str, 
			&d->textures->ea->w, &d->textures->ea->h);
	if (!d->textures->ea->xpm || !d->textures->no->xpm
		|| !d->textures->so->xpm || !d->textures->we->xpm)
	{
		free_all(d);
		mlx_destroy_window(d->mlx, d->win);
		error_exit(E_XPM);
	}
	return (0);
}
