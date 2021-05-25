/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 08:16:34 by oel-yous          #+#    #+#             */
/*   Updated: 2021/02/08 10:11:49 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_pressed(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		ft_exit(mlx);
	if (key == KEY_W)
		g_p.updirection = 1;
	if (key == KEY_S)
		g_p.downdirection = 1;
	if (key == KEY_D)
		g_p.rightdirection = 1;
	if (key == KEY_A)
		g_p.leftdirection = 1;
	if (key == RIGHT_ARROW)
		g_p.rightrangle = 1;
	if (key == LEFT_ARROW)
		g_p.leftrangle = 1;
	return (0);
}

int		key_released(int key)
{
	if (key == KEY_W)
		g_p.updirection = 0;
	if (key == KEY_S)
		g_p.downdirection = 0;
	if (key == KEY_D)
		g_p.rightdirection = 0;
	if (key == KEY_A)
		g_p.leftdirection = 0;
	if (key == RIGHT_ARROW)
		g_p.rightrangle = 0;
	if (key == LEFT_ARROW)
		g_p.leftrangle = 0;
	return (0);
}

int		move(t_mlx *mlx)
{
	t_args		arg;
	int			i;

	g_sp = -1;
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx->img = mlx_new_image(mlx->mlx, g_win.width, g_win.height);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sline, &mlx->end);
	update_player();
	castall_rays();
	generate3d_projection(mlx);
	while (++g_sp <= g_sptcount)
		ft_sprite(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

int		update_player(void)
{
	if (g_p.updirection == 1)
	{
		if (!(is_wall(g_p.x + cos((g_p.direction) * (PI / 180)) * 10,
		g_p.y + sin((g_p.direction) * (PI / 180)) * 10)))
		{
			g_p.y = g_p.y + sin((g_p.direction) * (PI / 180)) * MVSPD;
			g_p.x = g_p.x + cos((g_p.direction) * (PI / 180)) * MVSPD;
		}
	}
	if (g_p.downdirection == 1)
	{
		if (!(is_wall(g_p.x - cos((g_p.direction) * (PI / 180)) * 10,
		g_p.y - sin((g_p.direction) * (PI / 180)) * 10)))
		{
			g_p.y = g_p.y - sin((g_p.direction) * (PI / 180)) * MVSPD;
			g_p.x = g_p.x - cos((g_p.direction) * (PI / 180)) * MVSPD;
		}
	}
	help_player();
	return (0);
}

void	ft_set_ply(char c)
{
	if (c == 'N')
	{
		g_p.playerp = 'N';
		g_p.direction = 270;
	}
	else if (c == 'E')
	{
		g_p.playerp = 'E';
		g_p.direction = 360;
	}
	else if (c == 'S')
	{
		g_p.playerp = 'S';
		g_p.direction = 90;
	}
	else if (c == 'W')
	{
		g_p.playerp = 'W';
		g_p.direction = 180;
	}
}
