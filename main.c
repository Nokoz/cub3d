/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:40:16 by salowie           #+#    #+#             */
/*   Updated: 2024/03/25 10:55:17 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/cub3d.h"

int	main(int ac, char **av)
{
	t_datas	*datas;
	t_game	*game;

	datas = NULL;
	game = NULL;
	datas = start_parsing(ac, av, game);
	start_cast(datas);
	free_all(datas);
	return (0);
}

t_datas	*start_parsing(int argc, char **argv, t_game *game)
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
	game = malloc(sizeof(t_game));
	if (!game)
		error_exit(E_MALLOC);
	datas->game = game;
	check_arg(argc, lib, datas);
	init_variables(datas, lib);
	check_map(datas);
	handle_mlx(datas);
	return (datas);
}
