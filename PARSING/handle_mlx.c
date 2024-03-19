/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:48:12 by salowie           #+#    #+#             */
/*   Updated: 2024/03/19 15:01:18 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/common.h"

int	close_event(t_datas *datas)
{
	free_all(datas);
	exit(0);
}

int	key_event(int keycode, void *param)
{
	t_datas	*datas;

	datas = (t_datas *)param;
	if (keycode == 53)
	{
		mlx_destroy_window(datas->mlx, datas->win);
		exit (0);
	}
	// rajouter partie Guillaume
	return (0);
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
		mlx_destroy_window(datas->mlx, datas->win);
		free_all(datas);
		error_exit(E_WIN);
	}
	assign_textures(datas);
	//draw_texture(datas, x, y);
//	mlx_hook(datas->win, 17, 0, close_event, datas);
//	mlx_hook(datas->win, 2, 0, key_event, datas);
//	mlx_loop(datas->mlx);
	return (0);
}
