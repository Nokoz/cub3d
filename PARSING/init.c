/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:49:04 by salowie           #+#    #+#             */
/*   Updated: 2024/03/19 14:51:17 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/common.h"

static void	finding_textures(char **str, int i, t_datas *datas)
{
	if (ft_strncmp(str[i], "NO ", 3) == 0)
		datas->textures->no->str = ft_strdup(str[i] + 5);
	if (ft_strncmp(str[i], "SO ", 3) == 0)
		datas->textures->so->str = ft_strdup(str[i] + 5);
	if (ft_strncmp(str[i], "WE ", 3) == 0)
		datas->textures->we->str = ft_strdup(str[i] + 5);
	if (ft_strncmp(str[i], "EA ", 3) == 0)
		datas->textures->ea->str = ft_strdup(str[i] + 5);
	if (ft_strncmp(str[i], "F ", 2) == 0)
	{
		keep_rgb_datas(str[i], datas, 'F', str);
		assign_rgb(datas, datas->rgb_datas->str_floor, 'F', str);
	}
	if (ft_strncmp(str[i], "C ", 2) == 0)
	{
		keep_rgb_datas(str[i], datas, 'C', str);
		assign_rgb(datas, datas->rgb_datas->str_sky, 'C', str);
	}
}

static void	finding_datas(char **doc, t_datas *datas)
{
	int	i;

	i = -1;
	while (doc[++i])
	{
		finding_textures(doc, i, datas);
		if (is_map(doc[i]) == 0)
		{
			if ((datas->textures->ea->str == NULL)
				|| (datas->textures->we->str == NULL)
				|| (datas->textures->so->str == NULL)
				|| (datas->textures->no->str == NULL)
				|| (datas->rgb_datas->str_floor == NULL)
				|| (datas->rgb_datas->str_sky == NULL))
			{
				ft_free_2d_char(&doc);
				free_all(datas);
				error_exit(E_DOC);
			}
			datas->map = copy_map(doc, i, datas);
			break ;
		}
	}
}

static void	init_textures(t_datas *datas)
{
	datas->textures = malloc(sizeof(t_texture));
	if (!datas->textures)
	{
		free_all(datas);
		error_exit(E_MALLOC);
	}
	datas->textures->no = malloc(sizeof(t_texture_struct));
	datas->textures->so = malloc(sizeof(t_texture_struct));
	datas->textures->we = malloc(sizeof(t_texture_struct));
	datas->textures->ea = malloc(sizeof(t_texture_struct));
	if (!datas->textures->no || !datas->textures->so || !datas->textures->we
		|| !datas->textures->ea)
	{
		free_all(datas);
		error_exit(E_MALLOC);
	}
	datas->textures->no->str = NULL;
	datas->textures->so->str = NULL;
	datas->textures->we->str = NULL;
	datas->textures->ea->str = NULL;
}

static void	init_rgb_datas(t_datas *datas)
{
	datas->rgb_datas = malloc(sizeof(t_rgb));
	if (!datas->rgb_datas)
	{
		free_all(datas);
		error_exit(E_MALLOC);
	}
	datas->rgb_datas->str_floor = NULL;
	datas->rgb_datas->str_sky = NULL;
}

void	init_variables(t_datas *datas, char *lib)
{
	char	**doc;

	init_textures(datas);
	init_rgb_datas(datas);
	doc = convert_doc(lib, datas);
	finding_datas(doc, datas);
	ft_free_2d_char(&doc);
}
