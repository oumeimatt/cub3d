/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:25:46 by oel-yous          #+#    #+#             */
/*   Updated: 2021/02/08 10:10:00 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_sprite(t_mlx *mlx, int x_fs, int y_fs, int sp_size)
{
	int		i;
	int		j;
	int		color;

	i = -1;
	while (++i < sp_size)
	{
		if (x_fs + i < 0 || x_fs + i > g_win.width)
			continue;
		if (x_fs + i < g_win.width)
			if (g_r[x_fs + i].distance < g_spt[g_sp].distance)
				continue;
		j = -1;
		while (++j < sp_size)
		{
			if ((j * TS / sp_size) >= 0 && (j * TS / sp_size)
			< g_win.width && (i * TS / sp_size) >= 0 &&
			(i * TS / sp_size) < g_win.height)
				color =
				g_spt[g_sp].data[TS * (j * TS / sp_size) + (i * TS / sp_size)];
			if (color != 0 && (x_fs + i) >= 0 && (x_fs + i) < g_win.width
			&& (y_fs + j) >= 0 && (y_fs + j) < g_win.height)
				my_mlx_pixel_put(mlx, x_fs + i, y_fs + j, color);
		}
	}
}

void	sprite_traits(t_mlx *mlx)
{
	float	x_offset;
	float	y_offset;
	float	sp_size;
	float	sp_angle;
	float	pl_angle;

	pl_angle = (g_p.direction * M_PI / 180);
	pl_angle = normalise_angle(pl_angle);
	sp_angle = atan2(-g_p.y + (g_spt[g_sp].y),
							-g_p.x + (g_spt[g_sp].x));
	while (sp_angle - pl_angle > M_PI)
		sp_angle -= TWO_PI;
	while (sp_angle - pl_angle < -M_PI)
		sp_angle += TWO_PI;
	sp_size = (g_win.width / g_spt[g_sp].distance * TS);
	x_offset = (sp_angle - pl_angle) /
		(60 * M_PI / 180) * g_win.width + (g_win.width / 2 - sp_size / 2);
	y_offset = (g_win.height / 2 - sp_size / 2);
	render_sprite(mlx, x_offset, y_offset, sp_size);
}

void	bubble_sort(void)
{
	int			i;
	int			j;
	t_spt		tmp;

	i = 0;
	while (i < g_sptcount)
	{
		j = 0;
		while (j < g_sptcount - i - 1)
		{
			if (g_spt[j].distance <= g_spt[j + 1].distance)
			{
				tmp = g_spt[j];
				g_spt[j] = g_spt[j + 1];
				g_spt[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	update_sprite(void)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < g_map_height)
	{
		j = 0;
		while (j < g_map_width)
		{
			if (g_map[i][j] == '2')
			{
				g_spt[k].x = j * TS + (TS / 2);
				g_spt[k].y = i * TS + (TS / 2);
				g_spt[k].distance =
				dist_betweenpts(g_spt[k].x, g_spt[k].y, g_p.x, g_p.y);
				k++;
			}
			j++;
		}
		i++;
	}
	bubble_sort();
}

void	ft_sprite(t_mlx *mlx)
{
	update_sprite();
	sprite_traits(mlx);
}
