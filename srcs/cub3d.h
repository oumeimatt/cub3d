/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:50:35 by oel-yous          #+#    #+#             */
/*   Updated: 2021/02/08 10:49:52 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>

# define BUFFER_SIZE 1000
# define KEY_ESC 53
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define MAXINT 2147483647
# define MAX_H 1440
# define MAX_W 2560
# define PI M_PI
# define TWO_PI 6.28318530718
# define TS 64
# define MVSPD 7
# define FOV_ANGLE 1.0471975512
# define TEX_W TS
# define TEX_H TS
# define RGB "RGB INVALID\n"
# define INV_PATH "PATH INVALID TO TEXTURE OR SPRITE\n"
# define RES "RESOLUTION INVALID\n"
# define ARGS "TOO MUCH OR NEED MORE ARGS IN MAP FILE\n"
# define INV_LINE "LINE EMPTY OR INVALID // MAP FILE INVALID\n"
# define INK_CHAR "UNKNOWN CHAR IN MAP OR MORE THAN ONE PLAYER\n"
# define MAP_CLS "MAP NOT CLOSE OR MAP NOT EXIST\n"
# define NEW_LINE "MAP HAS A NEW LINE\n"
# define ARG "NEED MORE ARGUMENTS OR TOO MUCH ARGUMENTS\n"
# define MAP "U NEED A MAP FILE IN FORMAT *.CUB\n"
# define SAVE "SAVE ERROR\n"

typedef struct	s_args
{
	int		floor_r;
	int		floor_g;
	int		floor_b;
	int		ceil_r;
	int		ceil_g;
	int		ceil_b;
	char	floor;
	char	ceil;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*sprite;
	int		i;
}				t_args;

typedef struct	s_mlx
{
	void	*img;
	void	*mlx;
	void	*win;
	int		*data;
	char	*addr;
	int		sline;
	int		bpp;
	int		end;
}				t_mlx;

typedef struct	s_player
{
	int		count;
	int		updirection;
	int		downdirection;
	int		leftdirection;
	int		rightdirection;
	int		rightrangle;
	int		leftrangle;
	int		direction;
	int		playerp;
	float	x;
	float	y;
}				t_player;

typedef struct	s_rays
{
	float		ray_angle;
	float		wallhitx;
	float		wallhity;
	float		distance;
	int			rayup;
	int			raydown;
	int			rayleft;
	int			rayright;
	int			washit_vertical;
}				t_rays[3500];

typedef struct	s_all
{
	int		is_raydown;
	int		is_rayup;
	int		is_rayleft;
	int		is_rayright;
	float	ystep;
	float	xstep;
	float	xintercept;
	float	yintercept;
	int		fnd_hrzwallhits;
	int		fnd_vrtwallhits;
	float	hrzhitx;
	float	hrzhity;
	float	vrthitx;
	float	vrthity;
	float	nxthrztchx;
	float	nxthrztchy;
	float	nxtvrttchy;
	float	nxtvrttchx;
	float	xcheck;
	float	ycheck;
	float	vrthitdis;
	float	hrzhitdis;
}				t_all;

typedef struct	s_win
{
	int		width;
	int		height;
}				t_win;

typedef struct	s_3d
{
	int		wallstripth;
	float	distprojplane;
	float	projwallheight;
	int		walltoppixel;
	int		wallbottompixel;
	float	perpdistance;
	int		i;
	int		y;
}				t_3d;

typedef struct	s_tex
{
	void		*ptr;
	int			img_width;
	int			img_height;
	int			bpp;
	int			size_line;
	int			endian;
	int			offset_x;
	int			offset_y;
	int			dst_ftop;
	int			color;
}				t_tex;

typedef struct	s_spt
{
	void		*ptr;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
	int			width;
	int			height;
	float		x;
	float		y;
	float		distance;
}				t_spt;

typedef struct	s_bmp
{
	char		header[54];
	int			filesize;
	int			offsetbytes;
	int			bisize;
	int			bi_planes;
	int			bitcount;
	int			imagesize;
	int			width_in_bytes;
	int			pos;
	int			fd;
	int			i;
	int			j;
	int			count_sp;
	int			*pixel;
}				t_bmp;

typedef struct	s_count
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		m;
	int		n;
	int		p;
	int		t;
	int		s;
}				t_count;

t_tex		g_tex;
t_count		g_counts;
t_win		g_win;
t_player	g_p;
t_rays		g_r;
t_3d		g_3d;
t_args		g_args;
t_spt		g_spt[1024];
int			g_save;
int			g_sp;
int			g_file_size;
int			g_count_args;
int			g_map_width;
int			g_map_height;
int			g_part1;
int			g_part2;
int			g_player;
char		g_map[1024][1024];
int			g_sptcount;
int			*g_texnorth;
int			*g_texsouth;
int			*g_texwest;
int			*g_texeast;

int				get_next_line(int fd, char **line);
int				ft_free(char **s1, int ret);
int				ft_line(char **p, char **line, int ret);
void			my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void			draw_rectangle(t_mlx *mlx, int x, int y);
void			draw_map(void);
void			draw_line(t_mlx *mlx, float x, float y, float x1, float y1);
void			put_player(t_mlx *mlx, int r);
void			init_textures(t_mlx *mlx);
void			init_sprite(t_mlx *mlx);
void			init_args();
int				num_lenght(char *str);
int				help_res(char *line, int j);
void			init_counts();
void			error_des(char *str);
void			ft_error(int err);
int				ft_error2(int err);
void			error_args(char *str);
int				ft_exit(t_mlx *mlx);
void			check_maps_args(char *line);
int				check_resolution(char *line);
int				check_floor(char *line);
int				check_ceil(char *line);
int				check_textures(char *line);
void			is_player();
void			check_map_close();
int				first_line(char *line);
void			handle_error(int i, int j);
int				valid_line(char *line);
int				check_invldline_part1(char *line);
int				invld_line_cf(char *line);
int				invld_line_res(char *line);
int				skip_comma(char *line);
int				ft_map_args(char *line);
int				num_lenght(char *str);
int				check_map_args2(char *line);
int				valid_map_line(char *line);
void			init_map(void);
int				surrounder_by_walls(char *line);
void			error_map(char *line);
char			*ft_strcpy(char *dest, char *src);
void			part1(char *line);
void			read_file(int fd, char *line);
int				update(t_mlx *mlx);
void			initialise_window(t_mlx *mlx);
int				check_no_tex(char *line);
int				check_so_tex(char *line);
int				check_ea_tex(char *line);
int				check_we_tex(char *line);
int				check_sprite(char *line);
void			check_args(int argc, char **argv);
int				main (int argc, char **argv);
int				key_pressed(int key, t_mlx *mlx);
int				key_released(int key);
int				move(t_mlx *mlx);
int				update_player(void);
int				is_wall(float x, float y);
void			ft_set_ply(char c);
void			cast_ray(float rayangle, int i);
void			castall_rays(void);
float			dist_betweenpts(float x1, float y1, float x2, float y2);
void			help_player(void);
float			normalise_angle(float angle);
void			init_horz(float rayangle, t_all *all);
void			cast_horz(float rayangle, t_all *all);
void			init_vert(float rayangle, t_all *all);
void			cast_vert(float rayangle, t_all *all);
void			generate3d_projection(t_mlx *mlx);
void			color_ceiling(t_mlx *mlx, int i, int y);
unsigned int	convert_rgb(unsigned int r, unsigned int g, unsigned int b);
void			floor_ceiling(t_mlx *mlx);
void			set_textures(t_mlx *mlx);
void			render_sprite(t_mlx *mlx, int x_fs, int y_fs, int sp_size);
void			sprite_traits(t_mlx *mlx);
void			ft_sprite(t_mlx *mlx);
void			bubble_sort(void);
void			update_sprite(void);
void			ft_bmp(t_mlx *mlx);
void			bmp_initialize(t_bmp *bmp);

#endif
