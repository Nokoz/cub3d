/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:48:17 by salowie           #+#    #+#             */
/*   Updated: 2024/03/26 12:14:16 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/cub3d.h"

int	rgbtoint(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

static int	is_neg_or_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			return (1);
		if (str[i] == '+')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	assign_rgb(t_datas *datas, char *color, char x, char **doc)
{
	char	**rgb;
	int		r[3];
	int		n_or_a;
	int		i;

	i = 0;
	rgb = ft_split(color, ',');
	while (rgb[i])
	{
		n_or_a = is_neg_or_alpha(rgb[i]);
		r[i] = ft_atoi(rgb[i]);
		if (r[i] < 0 || r[i] > 255 || n_or_a == 1 || ft_strlen_2d(rgb) != 3)
		{
			ft_free_2d_char(&doc);
			ft_free_2d_char(&rgb);
			free_all(datas);
			error_exit(E_COLOR);
		}
		i++;
	}
	ft_free_2d_char(&rgb);
	if (x == 'C')
		datas->rgb_datas->sky = rgbtoint(r[0], r[1], r[2]);
	if (x == 'F')
		datas->rgb_datas->floor = rgbtoint(r[0], r[1], r[2]);
}

void	keep_rgb_datas(char *str, t_datas *datas, char x, char **doc)
{
	if (x == 'C')
	{
		datas->rgb_datas->str_sky = ft_strdup_no_space(str + 2);
		if (!datas->rgb_datas->str_sky)
		{
			ft_free_2d_char(&doc);
			free_all(datas);
			error_exit(E_MALLOC);
		}
	}
	if (x == 'F')
	{
		datas->rgb_datas->str_floor = ft_strdup_no_space(str + 2);
		if (!datas->rgb_datas->str_floor)
		{
			ft_free_2d_char(&doc);
			free_all(datas);
			error_exit(E_MALLOC);
		}
	}
}
