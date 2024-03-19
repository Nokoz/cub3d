/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:28:32 by gvardaki          #+#    #+#             */
/*   Updated: 2024/03/19 15:33:52 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

# define H 1080
# define W 1920
# define MAPX 29
# define MAPY 8
# define DR	0.01745329

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_UP		126
# define KEY_RIGHT	124
# define KEY_DOWN 	125
# define KEY_LEFT	123
# define KEY_ESC	53

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_map
{
	char 	**map;
	int		x;
	int		y;
}				t_map;

typedef struct s_ray
{
	int		r;
	int		mx;
	int		my;
	int		mp;
	//depth of field
	int		dof;
	float	rx;
	float	ry;
	float	ra;
	//offset
	float	xo;
	float	yo;
}				t_ray;

typedef struct s_game
{	
	void		*mlx_ptr;
	void		*win_ptr;
	float		px;
	float		py;
	float		pdx;
	float		pdy;
	float		pa;
	t_map		map;
	t_img		*img;
	t_ray		*ray;
	void		*data;
}				t_game;

//int		noko(t_datas *d);
//void	ft_init_win(t_datas *d);
float 	ft_start_dri(char c);
void	ft_show_mini(t_game *game);
void	ft_show_ray(t_game *game);
void	ft_draw_background(t_game *game);
void	ft_show_player(t_game *game);
void	ft_print_square(t_game *game, int w, int h, char c);
int		ft_frame_loop(t_game *game);
int		ft_key_handle(int key, t_game *game);
void	img_pix_put(t_img *img, int x, int y, int color);
void	ft_cast_ray(t_game *g);
float	ft_cast_hori(t_ray *ray, t_game *g, float x, float y);
float	ft_cast_verti(t_ray *ray, t_game *g, float x, float y);
void	ft_iter_offset(t_ray *ray, t_game *g, float xo, float yp);
float	ft_ray_dist(t_game *g);
void	ft_draw_line(t_game *g, int x, int y, float wall_h);
float	ft_get_wall_h(t_game *g, float dist);
void	ft_draw_ray(t_game *g, float wall_h, float line_o, int ray);
void	ft_draw_walls(t_game *g, int ray);

void	ft_move_up(t_game *g);
void	ft_move_down(t_game *g);
void	ft_move_left(t_game *g);
void	ft_move_right(t_game *g);
void	ft_rotate(t_game *g, int key);

//wrapper
void	*new_img(void *mlx_ptr);
char	*get_addr(t_img *i);
int		put_img(t_game *g);
int		destroy_img(t_game *g);
#endif
