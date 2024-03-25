/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:48:12 by salowie           #+#    #+#             */
/*   Updated: 2024/03/25 10:46:47 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/cub3d.h"

int	close_event(t_datas *datas)
{
	free_all(datas);
	exit(0);
}

int	handle_mlx(t_datas *datas)
{
	datas->mlx = mlx_init();
	if (!datas->mlx)
	{
		free_all(datas);
		error_exit(E_MLX);
	}
	datas->win = mlx_new_window(datas->mlx, 1920, 1080, "Three dies");
	if (!datas->win)
	{
		free_all(datas);
		error_exit(E_WIN);
	}
	assign_textures(datas);
	mlx_hook(datas->win, 17, 0, close_event, datas);
	return (0);
}
