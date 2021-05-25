/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:21:31 by oel-yous          #+#    #+#             */
/*   Updated: 2021/02/07 18:26:06 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	part1(char *line)
{
	if (check_invldline_part1(line) == 1)
		check_maps_args(line);
	if (ft_map_args(line) == 8)
		g_part1 = 1;
	if (check_invldline_part1(line) == -1)
		ft_error(5);
	if (g_counts.i > 1 || g_counts.j > 1 || g_counts.k > 1 || g_counts.l > 1
	|| g_counts.m > 1 || g_counts.n > 1 || g_counts.p > 1 || g_counts.t > 1)
		ft_error(4);
}

int		update(t_mlx *mlx)
{
	mlx_hook(mlx->win, 17, 0L, ft_exit, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, key_pressed, mlx);
	mlx_hook(mlx->win, 3, 1L << 1, key_released, (void *)0);
	move(mlx);
	return (0);
}

void	initialise_window(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, g_win.width, g_win.height, "CUB3D");
	mlx->img = mlx_new_image(mlx->mlx, g_win.width, g_win.height);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sline, &mlx->end);
}

void	read_file(int fd, char *line)
{
	int ret;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (g_part1 == 0)
		{
			part1(line);
			free(line);
		}
		else if (g_part1 == 1 && first_line(line) != 0)
			error_args(INV_LINE);
		if ((g_part1 == 3) && g_part2 == 1)
		{
			ft_strcpy(g_map[g_map_height], line);
			free(line);
		}
	}
	if (g_part1 == 3 && g_part2 == 1)
	{
		ft_strcpy(g_map[g_map_height], line);
		free(line);
	}
	else
		ft_error(7);
}
