/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:48:17 by salowie           #+#    #+#             */
/*   Updated: 2024/03/21 11:54:15 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/common.h"

int	rgbtoint(int r, int g, int b)
{
	return ((r * 65536) + (g * 256) + b);
}

static int	is_neg_or_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			return (1);
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	assign_rgb(t_datas *datas, char *color, char x, char **doc)
{
	char	**datas_rgb;
	int		res[3];
	int		neg_or_alpha;
	int		i;

	i = 0;
	datas_rgb = ft_split(color + 2, ',');
	while (datas_rgb[i])
	{
		neg_or_alpha = is_neg_or_alpha(datas_rgb[i]);
		res[i] = ft_atoi(datas_rgb[i]);
		if (res[i] < 0 || res[i] > 255 || neg_or_alpha == 1)
		{
			ft_free_2d_char(&doc);
			ft_free_2d_char(&datas_rgb);
			free_all(datas);
			error_exit(E_COLOR);
		}
		i++;
	}
	ft_free_2d_char(&datas_rgb);
	if (x == 'C')
		datas->rgb_datas->sky = rgbtoint(res[0], res[1], res[2]);
	if (x == 'F')
		datas->rgb_datas->floor = rgbtoint(res[0], res[1], res[2]);
}

void	keep_rgb_datas(char *str, t_datas *datas, char x, char **doc)
{
	if (x == 'C')
	{
		datas->rgb_datas->str_sky = malloc(sizeof(char) * ft_strlen(str) + 1);
		if (!datas->rgb_datas->str_sky)
		{
			ft_free_2d_char(&doc);
			free_all(datas);
			error_exit(E_MALLOC);
		}
		ft_strlcpy(datas->rgb_datas->str_sky, str, ft_strlen(str) + 1);
	}
	if (x == 'F')
	{
		datas->rgb_datas->str_floor = malloc(sizeof(char) * ft_strlen(str) + 1);
		if (!datas->rgb_datas->str_floor)
		{
			ft_free_2d_char(&doc);
			free_all(datas);
			error_exit(E_MALLOC);
		}
		ft_strlcpy(datas->rgb_datas->str_floor, str, ft_strlen(str) + 1);
	}
}
