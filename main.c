/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:40:16 by salowie           #+#    #+#             */
/*   Updated: 2024/03/22 10:39:46 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/cub3d.h"

t_datas	*sarah(int argc, char **argv);

int	main(int ac, char **av)
{
	t_datas	*datas;
	t_game	*game;

	datas = sarah(ac, av);
	game = malloc(sizeof(t_game));
	if (!game)
	{
		free_all(datas);
		error_exit(E_MALLOC);
	}
	datas->game = game;
	noko(datas);
	free_all(datas);
	//??destroy win, free mlx_ptr??
	return (0);
}

t_datas	*sarah(int argc, char **argv)
{
	char	*lib;
	t_datas	*datas;

	lib = argv[1];
	datas = malloc(sizeof(t_datas));
	if (!datas)
	{
		ft_freee((void *)datas);
		error_exit(E_MALLOC);
	}
	check_arg(argc, lib, datas);
	init_variables(datas, lib);
	check_map(datas);
	handle_mlx(datas);
	return (datas);
}
