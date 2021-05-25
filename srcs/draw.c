/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 10:04:52 by oel-yous          #+#    #+#             */
/*   Updated: 2021/02/07 18:42:23 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && x < g_win.width && y > 0
		&& y < g_win.height)
	{
		dst = mlx->addr + (y * mlx->sline + x * (mlx->bpp / 8));
		*(unsigned int*)dst = color;
	}
}

void	draw_map(void)
{
	int i;
	int j;

	i = 0;
	g_sptcount = 0;
	while (i < g_map_height)
	{
		j = 0;
		while (j < g_map_width)
		{
			if ((g_map[i][j] == 'S' || g_map[i][j] == 'E'
			|| g_map[i][j] == 'N' || g_map[i][j] == 'W') && g_p.count == 0)
			{
				g_p.count = 1;
				g_p.x = j * TS + (TS / 2);
				g_p.y = i * TS + (TS / 2);
				ft_set_ply(g_map[i][j]);
			}
			if (g_map[i][j] == '2')
				g_sptcount++;
			j++;
		}
		i++;
	}
}

int		check_invldline_part1(char *line)
{
	if (line[0] != 'R' && line[0] != 'N' &&
		line[0] != 'W' && line[0] != 'S' &&
		line[0] != 'E' &&
		line[0] != 'F' && line[0] != 'C' &&
		line[0] != '\0')
		return (-1);
	return (1);
}
