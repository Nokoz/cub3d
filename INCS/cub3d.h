/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:35:09 by salowie           #+#    #+#             */
/*   Updated: 2024/03/21 11:21:24 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>

# include "get_next_line.h"
//# include "../inc/ray.h"

# define E_ARG "ERROR !\nCause : wrong number of args, need 2 args\n"
# define E_FILE "ERROR !\nCause : wrong format of textfile, need .cub\n"
# define E_SYNTAXE "ERROR !\nCause : wrong syntaxe for floor or ceiling\n"
# define E_FD "ERROR !\nCause : opening of fd failed\n"
# define E_MAP "ERROR !\nCause : no map or invalid map\n"
# define E_DOC "ERROR !\nCause : wrong structure of doc .cub\n"
# define E_EMPTY "ERROR !\nCause : the .cub is empty\n"
# define E_MALLOC "ERROR !\nCause : malloc failed\n"
# define E_COLOR "ERROR !\nCause : Wrong value for the color\n"
# define E_DATAS "ERROR !\nCause : Too much colors or textures infos in .cub\n"
# define E_FD "ERROR !\nCause : opening of fd failed\n"
# define E_PLAYER "ERROR !\nCause : wrong number of player for this game\n"
# define E_PATH "ERROR !\nCause : the map is not closed or contain space\n"
# define E_MLX "ERROR !\nCause : the MinilibX is crashed\n"
# define E_XPM "ERROR !\nCause : image can't download\n"
# define E_WIN "ERROR !\nCause : the window is crashed\n"

typedef struct s_texture_struct {
	void	*xpm;
	char	*str;
	char	*data;
	int		w;
	int		h;
    int		size_l;
    int		bpp;
    int		endian;
}				t_texture_struct;

typedef struct s_texture {
	t_texture_struct	*no;
	t_texture_struct	*so;
	t_texture_struct	*we;
	t_texture_struct	*ea;
}				t_texture;

typedef struct s_rgb {
	char	*str_floor;
	char	*str_sky;
	int		floor;
	int		sky;
}				t_rgb;

typedef struct s_datas {
	t_texture	*textures;
	t_rgb		*rgb_datas;
	t_game		*game;
	char		**map;
	int			map_x;
	int			map_y;
	void		*mlx;
	void		*win;
	int			nbr_of_player;
	int			start_x;
	int			start_y;
	char		orientation;
	bool		openmap;
}				t_datas;

void	ft_init_win(t_datas *d);
int		noko(t_datas *d);
void	ft_draw_background(t_datas * data);
int		ft_frame_loop(t_game *game, t_datas *d);
int		ft_key_handle(int key, t_datas * d);

// HANDLE MLX //
int		handle_mlx(t_datas *datas);
int		assign_textures(t_datas *d);

// DRAWING // 
int 	get_pixel_color(t_texture_struct *texture, int x, int y);
int		draw_texture(t_datas *datas, int x, int y);

// PARSING //
void	init_variables(t_datas *datas, char *lib);
void	check_arg(int argc, char *lib, t_datas *datas);
int		is_map(char *str);
int		check_map(t_datas *datas);
char	**copy_map(char **doc, int i, t_datas *datas);

// PATH FINDING //
void	dupmap_init(t_datas *d);

// CONVERT //
char	**convert_doc(char *lib, t_datas *datas);
void	keep_rgb_datas(char *str, t_datas *datas, char x, char **doc);
void	assign_rgb(t_datas *datas, char *color, char x, char **doc);
int		rgbtoint(int r, int g, int b);

// UTILS //
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen_double_tab(char **tab);
char	*ft_strdup_no_tab(char *s1, int i, int j, int x);
int		ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
int		nbr_tab(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
int		exist(char *wall_side_str, t_datas *datas);

// ERROR & FREE //
void	error_exit(char *str);
void	ft_free_2d_char(char ***str_ptr);
void	ft_freee(void **value);
void	free_all(t_datas *d);

#endif
