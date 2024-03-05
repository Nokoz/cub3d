/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:32:28 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/05 11:57:56 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

int	main(int ac, char **av)
{
	t_game	*game;
	t_map	map;
	t_img	*img;
	(void)ac;
	(void)av;
	ft_printf("CUB3D\n");

	game = malloc(sizeof(t_game));
	img = malloc(sizeof(t_img));
	char *mapy = "11111\n10001\n10101\n10001\n10001\n11111\n";

	map.map = ft_split(mapy, '\n');
	game->map = map;
	game->img = img;
	game->px = 150;
	game->py = 150;
	game->pa = 0;
	game->pdx = cos(game->pa) * 5;
	game->pdy = sin(game->pa) * 5;
	ft_init_win(game);

	mlx_hook(game->win_ptr, 02, 1L<<0, ft_key_handle, game);
//	mlx_loop_hook(game->mlx_ptr, ft_frame_loop, game);
	mlx_loop(game->mlx_ptr);

	return (0);
}

void	ft_init_win(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, W, H, "cub3d");
}

int		ft_frame_loop(t_game *g)
{
	g->img->img = new_img(g->mlx_ptr);
	g->img->addr = get_addr(g->img);

		ft_draw_background(g);
		ft_show_mini(g);
		ft_show_player(g);
		ft_show_dir(g);
	ft_printf("ici\n");
		put_img(g);
		destroy_img(g);
		return (0);
}

int		ft_key_handle(int key, t_game *game)
{
	if (key == KEY_W)
		ft_move_up(game);
	//	game->py -=5;
	if (key == KEY_D)
		ft_move_right(game);
//		game->px +=5;
	if (key == KEY_S)
		ft_move_down(game);
//		game->py +=5;
	if (key == KEY_A)
		ft_move_left(game);
//		game->px -=5;
	if (key == KEY_ESC)
		exit(2);
	if (key == KEY_RIGHT)
		ft_rotate_right(game);
	if (key == KEY_LEFT)
		ft_rotate_left(game);
	ft_frame_loop(game);
	return (0);
}

