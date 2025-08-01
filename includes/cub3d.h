/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayoub <tayoub@@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:52:44 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/08/01 18:58:48 by tayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <errno.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define TEX_SIZE 64

# define MOVESPEED 0.04
# define ROTSPEED 0.028

# ifndef O_DIR
#  define O_DIR 00200000
# endif

enum	e_output
{
	SUCCESS,
	FAILURE,
	ERROR,
	BREAK,
	CONTINUE
};

enum	e_texture_index
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_texinfo
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_texinfo;

typedef struct s_mapinfo
{
	int		fd;
	int		line_count;
	char	*path;
	char	**file;
	int		height;
	int		width;
	int		index_end_of_map;
}	t_mapinfo;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_mapinfo	mapinfo;
	char		**map;
	t_player	player;
	t_ray		ray;
	int			**texture_pixels;
	int			**textures;
	t_texinfo	texinfo;
	t_img		minimap;
}	t_data;

//src/utils/exit.c
void	free_arr(void **arr);
int		free_data(t_data *data);
//src/utils/exit.c
void	clean_cub3d(t_data *data, int code);
int		exit_cub3d(t_data *data);
//src/utils/error.c
int		err_msg(char *detail, char *str, int code);
//src/init/init_data.c
void	init_img_clean(t_img *img);
void	init_ray(t_ray *ray);
void	init_data(t_data *data);
//src/init/init_mlx.c
void	init_img(t_data *data, t_img *image, int width, int height);
void	init_texture_img(t_data *data, t_img *image, char *path);
void	init_mlx(t_data *data);
//src/init/init_textures.c
void	init_texinfo(t_texinfo *tex);
void	init_textures(t_data *data);
//src/parsing/validate_arg.c
int		val_file(char *arg, bool cub_file);
//src/parsing/fill_dir_tex.c
int		fill_dir_tex(t_texinfo *tex, char *line, int j);
//src/parsing/fill_col_tex.c
int		fill_col_tex(t_data *data, t_texinfo *tex, char *line, int j);
//src/parsing/fill_file_data.c
int		get_file_data(t_data *data, char **map);
//src/parsing/parse_file.c
void	parse_data(char *path, t_data *data);
//src/parsing/utils.c
bool	white_spc(char c);
size_t	find_largest_len(t_mapinfo *map, int i);
//src/parsing/create_map.c
int		create_map(t_data *data, char **file, int i);
//src/parsing/check_borders.c
int 	check_map_borders(t_mapinfo *map, char **map_arr);
//src/parsing/check_map.c
int 	check_map(t_data *data, char **map_arr);
//src/parsing/check_tex.c
int		check_tex(t_data *data, t_texinfo *tex);
//src/player/input_handler.c   
void	input_listener(t_data *data);
//src/player/player_direction.c
void init_player_direction(t_data *data);
//src/player/player_mouvement.c
int	move(t_data *data);
//src/player/player_rotation.c
int	rotate(t_data *data, double rotdir);
//src/player/valid_position.c
int	validate_move(t_data *data, double new_x, double new_y);
//src/rendering/utils.c
void	set_im_pixel(t_img *image, int x, int y, int color);
//src/rendering/raycasting.c
int		raycasting(t_player *pl, t_data *data);
//src/rendering/render.c
void	render_raycast(t_data *data);
int		render(t_data *data);
//src/rendering/texture.c
void	init_texture_pixels(t_data *data);
void	update_texture_pixels(t_data *data, t_texinfo *tex, t_ray *ray, int x);

#endif