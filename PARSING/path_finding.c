/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:06:28 by salowie           #+#    #+#             */
/*   Updated: 2024/03/19 14:52:08 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/common.h"

static char	**create_mappy(t_datas *datas)
{
	char	**mappy;
	int		y;

	y = 0;
	mappy = malloc(sizeof(char *) * (ft_strlen_double_tab(datas->map) + 1));
	if (mappy == NULL)
	{
		free_all(datas);
		error_exit(E_MALLOC);
	}
	while (datas->map[y] && y <= ft_strlen_double_tab(datas->map))
	{
		mappy[y] = ft_strdup(datas->map[y]);
		y++;
	}
	mappy[y] = NULL;
	return (mappy);
}

static void	where_is_p(t_datas *datas)
{
	int	y;
	int	x;

	y = 0;
	while (datas->map[y] && y <= ft_strlen_double_tab(datas->map))
	{
		x = 0;
		while (datas->map[y][x] && x <= ft_strlen(datas->map[y]))
		{
			if (datas->map[y][x] == 'N' || datas->map[y][x] == 'S' ||
				datas->map[y][x] == 'W' || datas->map[y][x] == 'E')
			{
				datas->start_x = x;
				datas->start_y = y;
				datas->orientation = datas->map[y][x];
			}
			x++;
		}
		y++;
	}
}

static void	find_exit(char **mappy, t_datas *datas, int y, int x)
{
	if (y < 0 || x < 0 || y > ft_strlen_double_tab(datas->map)
		|| x > ft_strlen(datas->map[y]) || datas->map[y][x] == 32)
	{
		datas->openmap = true;
		return ;
	}
	if (mappy[y][x] == '1' || mappy[y][x] == '2')
		return ;
	else if (mappy[y][x] == '0')
		mappy[y][x] = '2';
	find_exit(mappy, datas, y + 1, x);
	find_exit(mappy, datas, y - 1, x);
	find_exit(mappy, datas, y, x + 1);
	find_exit(mappy, datas, y, x - 1);
}

void	dupmap_init(t_datas *d)
{
	char	**mappy;
	int		y;

	y = 0;
	mappy = create_mappy(d);
	where_is_p(d);
	d->openmap = false;
	find_exit(mappy, d, d->start_y, d->start_x);
	if (d->openmap == true)
	{
		free_all(d);
		ft_free_2d_char(&mappy);
		error_exit(E_PATH);
	}
	if (mappy)
		ft_free_2d_char(&mappy);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*str1;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	str1 = (char *)s1;
	str = malloc(sizeof(char) * ft_strlen(str1) + 1);
	if (!str)
		return (0);
	while (str1[i])
	{
		str[i] = str1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
