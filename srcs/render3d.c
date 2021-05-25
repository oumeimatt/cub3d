/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:43:55 by oel-yous          #+#    #+#             */
/*   Updated: 2021/02/07 18:38:19 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			generate3d_projection(t_mlx *mlx)
{
	g_3d.i = 0;
	g_3d.distprojplane = (g_win.width / 2) / tan(FOV_ANGLE / 2);
	while (g_3d.i < g_win.width)
	{
		g_3d.perpdistance = g_r[g_3d.i].distance * cos(g_r[g_3d.i].ray_angle
		- (g_p.direction * (PI / 180)));
		g_3d.projwallheight =
		(TS / g_3d.perpdistance) * g_3d.distprojplane;
		g_3d.wallstripth = (int)g_3d.projwallheight;
		g_3d.walltoppixel = (g_win.height / 2) - (g_3d.wallstripth / 2);
		g_3d.walltoppixel = g_3d.walltoppixel < 0 ? 0 : g_3d.walltoppixel;
		g_3d.wallbottompixel = g_3d.walltoppixel + g_3d.wallstripth;
		g_3d.wallbottompixel = g_3d.wallbottompixel > g_win.height ?
		g_win.height : g_3d.wallbottompixel;
		floor_ceiling(mlx);
		set_textures(mlx);
		g_3d.i++;
	}
}

unsigned int	convert_rgb(unsigned int r, unsigned int g, unsigned int b)
{
	int c;

	c = r;
	c = (c << 8) | g;
	c = (c << 8) | b;
	return (c);
}

void			floor_ceiling(t_mlx *mlx)
{
	g_3d.y = -1;
	while (++g_3d.y < g_3d.walltoppixel)
		my_mlx_pixel_put(mlx, g_3d.i, g_3d.y,
		convert_rgb(g_args.ceil_r, g_args.ceil_g, g_args.ceil_b));
	g_3d.y = g_3d.wallbottompixel - 1;
	while (++g_3d.y < g_win.height)
		my_mlx_pixel_put(mlx, g_3d.i, g_3d.y,
		convert_rgb(g_args.floor_r, g_args.floor_g, g_args.floor_b));
}

void			set_textures(t_mlx *mlx)
{
	g_3d.y = g_3d.walltoppixel - 1;
	g_tex.offset_x = g_r[g_3d.i].washit_vertical ?
	(int)g_r[g_3d.i].wallhity % TS : (int)g_r[g_3d.i].wallhitx % TS;
	while (++g_3d.y < g_3d.wallbottompixel)
	{
		g_tex.dst_ftop = g_3d.y + (g_3d.wallstripth / 2) - (g_win.height / 2);
		g_tex.offset_y = g_tex.dst_ftop * ((float)TEX_H / g_3d.wallstripth);
		if ((TEX_W * g_tex.offset_y + g_tex.offset_x) > 0)
		{
			if (g_r[g_3d.i].raydown && !g_r[g_3d.i].washit_vertical)
				g_tex.color = g_texnorth[(TEX_W * g_tex.offset_y)
									+ g_tex.offset_x];
			else if (g_r[g_3d.i].rayup && !g_r[g_3d.i].washit_vertical)
				g_tex.color = g_texsouth[(TEX_W * g_tex.offset_y)
									+ g_tex.offset_x];
			else if (g_r[g_3d.i].rayleft && g_r[g_3d.i].washit_vertical)
				g_tex.color = g_texeast[(TEX_W * g_tex.offset_y)
									+ g_tex.offset_x];
			else if (g_r[g_3d.i].rayright && g_r[g_3d.i].washit_vertical)
				g_tex.color = g_texwest[(TEX_W * g_tex.offset_y)
				+ g_tex.offset_x];
		}
		my_mlx_pixel_put(mlx, g_3d.i, g_3d.y, g_tex.color);
	}
}

int				is_wall(float x, float y)
{
	int		grid_x;
	int		grid_y;

	grid_x = floor(x / TS);
	grid_y = floor(y / TS);
	if (grid_y < 0 || grid_y >= g_map_height ||
	grid_x < 0 || grid_x >= g_map_width)
		return (0);
	if (g_map[grid_y][grid_x] == '1')
		return (1);
	return (0);
}
