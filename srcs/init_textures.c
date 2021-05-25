/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 10:07:13 by oel-yous          #+#    #+#             */
/*   Updated: 2021/02/07 18:19:52 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_mlx *mlx)
{
	g_tex.ptr = mlx_xpm_file_to_image(mlx->mlx, g_args.no,
	&g_tex.img_width, &g_tex.img_height);
	g_texnorth = (int *)mlx_get_data_addr(g_tex.ptr,
	&mlx->bpp, &mlx->sline, &mlx->end);
	g_tex.ptr = mlx_xpm_file_to_image(mlx->mlx, g_args.so,
	&g_tex.img_width, &g_tex.img_height);
	g_texsouth = (int *)mlx_get_data_addr(g_tex.ptr,
	&mlx->bpp, &mlx->sline, &mlx->end);
	g_tex.ptr = mlx_xpm_file_to_image(mlx->mlx, g_args.we,
	&g_tex.img_width, &g_tex.img_height);
	g_texwest = (int *)mlx_get_data_addr(g_tex.ptr,
	&mlx->bpp, &mlx->sline, &mlx->end);
	g_tex.ptr = mlx_xpm_file_to_image(mlx->mlx, g_args.ea,
	&g_tex.img_width, &g_tex.img_height);
	g_texeast = (int *)mlx_get_data_addr(g_tex.ptr,
	&mlx->bpp, &mlx->sline, &mlx->end);
}

void	init_sprite(t_mlx *mlx)
{
	int		spt_id;

	spt_id = 0;
	while (spt_id <= g_sptcount)
	{
		g_spt[spt_id].ptr = mlx_xpm_file_to_image(mlx->mlx,
		g_args.sprite, &g_spt[spt_id].width, &g_spt[spt_id].height);
		g_spt[spt_id].data = (int *)mlx_get_data_addr(g_spt[spt_id].ptr,
		&g_spt[spt_id].bpp,
		&g_spt[spt_id].size_line,
		&g_spt[spt_id].endian);
		spt_id++;
	}
	if (g_save == 1)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx->img = mlx_new_image(mlx->mlx, g_win.width, g_win.height);
		mlx->addr =
		mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sline, &mlx->end);
		update_player();
		castall_rays();
		generate3d_projection(mlx);
		ft_bmp(mlx);
	}
}
